#include <iostream>
#include "internal-header.hpp"

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
		return run_viewer();
	case 'r':
		return select();
	case 'd':
		return repeated_detection_mysterious();
	case 'v':
		return all_together();
	default: return 0;
	}
}
