/*
	C++ Loading Bar
	Created by x-2f
	10/10/2022
*/

#ifndef LOADING_H
#define LOADING_H

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <unistd.h>

class LoadingBar {
private:
	/*
		Checks whether all tasks are done.
	*/
	bool isFinished() {
		return tasks.size() == 0;
	}
	
	/*
		Prints the progress of all unfinished tasks.
	*/
	void printAll() {
		for (unsigned i = 0; i < tasks.size(); i += 2) {
			int iteration = *tasks[i];
			int total = *tasks[i + 1];
			float percentage = 1.0 * iteration / total;
			std::string line;
			for (int i = 0; i < barWidth; i++) {
				if (percentage <= 1.0 * i / barWidth) {
					line += empty;
				} else {
					line += fill;
				}
			}
			if (percentage > 1) {
				percentage = 1;
			}
			std::string pc = std::to_string((int)(100 * percentage)) + "%";
			if (pc.length() < 3) {
				pc = " " + pc;
			}
			std::string pre = prefix;
			std::string suf = suffix;
			if (pre.size() > 0) {
				pre = pre + " ";
			}
			if (suf.size() > 0) {
				suf = " " + suf;
			}
			std::cout << "\r" << pre << "[" << line << "] " << pc << suf << std::flush;
		}
	}

	/*
		Removes finished tasks and prints unfinished ones.
	*/
	void update() {
		printAll();
		unsigned i = 0;
		while (i < tasks.size()) {
			if (*tasks[i] >= *tasks[i + 1]) {
				tasks.erase(tasks.begin() + i, tasks.begin() + i + 1);
			} else {
				i += 2;
			}
		}
	}
protected:
	std::vector<int*> tasks;
	std::string prefix;
	std::string suffix;
	char empty;
	char fill;
	int barWidth;
public:
	/*
		Sets default values.
	*/
	LoadingBar() {
		barWidth = 40;
		empty = '-';
		fill = '#';
	}

	/*
		Sets prefix and suffix.
	*/
	LoadingBar(std::string prefix, std::string suffix) {
		barWidth = 40;
		this->prefix = prefix;
		this->suffix = suffix;
		empty = '-';
		fill = '#';
	}

	/*
		Destructor.
	*/
	~LoadingBar() {

	}

	/*
		Adds a task.
	*/
	void addTask(int &value, int &total) {
		tasks.push_back(&value);
		tasks.push_back(&total);
	}

	/*
		Starts looping and returns thread which must be joined elsewhere.
	*/
	std::thread start() {
		std::thread loop([this] {
			while (!isFinished()) {
				update();
				sleep(1);
			}
			std::cout << std::endl;
		});
		return loop;
	}

	void setPrefix(std::string s) { prefix = s; };
	void setSuffix(std::string s) { suffix = s; };

	void setEmptyChar(char c) { empty = c; };
	void setFillChar(char c) { fill = c; };

	//int getWidth() { return barWidth; };
	void setWidth(int n) { barWidth = n; };
};

#endif
