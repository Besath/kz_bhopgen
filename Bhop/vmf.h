#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "fmt/format.h"

class VMF
{
public:
	bool open_files();
	std::string get_file_start() { return vmf_start; }
	std::string get_file_end() { return vmf_end; }
	std::string get_solid() { return solid; }
	std::vector<std::string> get_uvs() const { return uv; }
private:
	const std::vector<std::string> uv = { "\"uaxis\" \"[1 0 0 0] 0.25\"\n\t\t\t\"vaxis\" \"[0 -1 0 0] 0.25\"", "\"uaxis\" \"[0 1 0 0] 0.25\"\n\t\t\t\"vaxis\" \"[0 0 -1 0] 0.25\"", "\"uaxis\" \"[1 0 0 0] 0.25\"\n\t\t\t\"vaxis\" \"[0 0 -1 0] 0.25\"" };
	std::string vmf_start;
	std::string vmf_end;
	std::string solid;
};