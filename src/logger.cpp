#include <stdio.h> // TODO [C++11] - to I/O Stream

#include "logger.h"

void log_memory(const char* message, bool allocated) {
	const char* allocd = (allocated) ? "[MEM-Allocation]" : "[MEM-Deallocation]";
	if (g_log_memory) {
		printf("%s %s\n", allocd, message);
	}
}

void log_action(const char* message) {
	if (g_log_game) {
		printf("%s\n", message);
	}
}