#include "vmf.h"

bool VMF::open_files()
{
	std::ifstream beginning("vmf_top.dat");
	std::ifstream end("vmf_bottom.dat");
	std::ifstream block("solid.dat");

	if (!beginning || !end || !block)
	{
		std::cerr << "Error opening files";
		return false;
	}
	else
	{
		vmf_start.assign((std::istreambuf_iterator<char>(beginning)),
			(std::istreambuf_iterator<char>()));

		vmf_end.assign((std::istreambuf_iterator<char>(end)),
			(std::istreambuf_iterator<char>()));

		solid.assign((std::istreambuf_iterator<char>(block)),
			(std::istreambuf_iterator<char>()));
	}

	return true;
}