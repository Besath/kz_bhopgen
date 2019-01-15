#include "block.h"
#include "vmf.h"

int main(int argc, char* argv[])
{
	if (argc != 11 || std::string(argv[1]) != "-blocks" || std::string(argv[3]) != "-width" || std::string(argv[5]) != "-height" || std::string(argv[7]) != "-distmin" || std::string(argv[9]) != "-distmax")
	{
		std::cout << "Usage: bhop -blocks # -width # -height # -distmin # -distmax #";
		return 0;
	}

	Block block{std::stoi(argv[2]), std::stoi(argv[4]), std::stoi(argv[6]), std::stoi(argv[8]), std::stoi(argv[10])};
	VMF vmf;

	std::vector<std::string> uvs = vmf.get_uvs();
	vmf.open_files();
	std::ofstream bhop;
	std::string tmp;
	std::string formatted;
	bhop.open("bhop.vmf");

	for (int i = 0; i < block.get_blocks(); i++)
	{
		formatted = fmt::format(vmf.get_solid(), block.get_left(), block.get_right(), block.get_bottom(), block.get_top(), block.get_base(), block.get_height(), uvs[0], uvs[1], uvs[2]);
		tmp += formatted;
		block.set_distance();
		block.set_direction();
		block.calculate_sides();
	}
	
	for (int i = 2; i < block.get_ids_count(); i++)
	{
		tmp.replace(tmp.find("%d"), 2, std::to_string(i));
	}
	bhop << vmf.get_file_start() << tmp << vmf.get_file_end();

	return 0;
}