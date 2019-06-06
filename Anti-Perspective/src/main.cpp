#include <iostream>
#include "internal-header.hpp"

std::string get_filename() {
	std::cout << "Image to view?\n";
	std::string file;
	std::cin >> file;
	std::cout << std::endl;
	return file;
}

int main(int argc, const char * argv[]) {
	std::cout << "Select mode:\n";
	std::cout << "s for the viewer with sliders,\n";
	std::cout << "r to select ROIs for Facemark,\n";
	std::cout << "d for real-time face detection,\n";
	std::cout << "v to try to use the auto-viewer.\n";
	char mode;
	std::cin >> mode;
	std::cout << "\nLoading" << std::endl;
	switch (mode) {
	case 's':
		return run_viewer(get_filename());
	case 'r':
		return select();
	case 'd':
		return repeated_detection_mysterious();
	case 'v':
		return all_together(get_filename());
	default: return 0;
	}
}
