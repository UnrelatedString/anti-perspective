#include <iostream>
#include "internal-header.hpp"

int main(int argc, const char * argv[]) {
	std::cout << "Select mode:\n";
	std::cout << "s for the viewer with sliders,\n";
	std::cout << "r to select ROIs for Facemark,\n";
	std::cout << "d for real-time face detection.\n";
	char mode;
	std::cin >> mode;
	switch (mode) {
	case 's':
		return run_viewer();
	case 'r':
		return select();
	case 'd':
		return repeated_detection_mysterious();
	default: return 0;
	}
}
