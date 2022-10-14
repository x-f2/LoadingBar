#include <iostream>
#include "../LoadingBar.h"

int main() {
	srand(time(NULL));

	int packages = 0;
	int packagetotal = 100;
	LoadingBar bar;
	bar.addTask(packages, packagetotal);
	bar.setPrefix("Progress:");
	bar.setSuffix("Complete.");
	
	std::thread s = bar.start();
	while (packages < packagetotal) {
		packages += rand() % 10 + 1;
		sleep(1);
	}
	s.join();
	return 0;
}
