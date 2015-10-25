#include <stdlib.h>
#include <stdio.h> // TODO [C++11] - to I/O Stream

#include "logger.h"

static CustomSystemLogger* logger = logger->initialize();
static char* write_string = (char*) malloc(sizeof(char) * 256);

void log_memory(const char* message) {
	logger->log_heap_allocation(message);
}

void log_memory(const char* message, bool allocated) {
	log_memory(message, allocated, NULL);
}

void log_memory(const char* message, bool allocated, char* appendDecoration) {
	logger->appendDecoration(appendDecoration);
	const char* allocd = (allocated) ? "[MEM - Allocation]" : "[MEM-Deallocation]";

	for (int i=0;i<256;i++) { write_string[i] = '\0'; }
	sprintf(write_string, "%s %s\n", allocd, message);
	logger->log_heap_allocation(write_string);
}

void log_action(const char* message) {
	if (g_log_game) {
		printf("%s\n", message);
	}
}