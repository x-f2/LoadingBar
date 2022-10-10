/*
	C++ Loading Bar
	by Andy Byron
	10/10/2022
*/

#ifndef LOADING_H
#define LOADING_H

#include <string>
#include <vector>
#include <thread>
#include <unistd.h>

class LoadingBar {
private:
	bool isFinished();
	void printAll();
	void update();
protected:
	std::vector<int*> tasks;
	std::string prefix;
	std::string suffix;
	char empty;
	char fill;
	int barWidth;
public:
	LoadingBar();
	LoadingBar(std::string prefix, std::string suffix);
	~LoadingBar();

	void addTask(int &value, int &total);
	std::thread start();

	void setPrefix(std::string s) { prefix = s; };
	void setSuffix(std::string s) { suffix = s; };

	void setEmptyChar(char c) { empty = c; };
	void setFillChar(char c) { fill = c; };

	//int getWidth() { return barWidth; };
	void setWidth(int n) { barWidth = n; };
};

#endif
