#ifndef LOGGER_H
#define LOGGER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int MAX_DECORATION_LENGTH = 12;

// Settable from CLI switches
extern bool g_log_memory;
extern bool g_log_game;

/**
 * Logger Utility
 * 
 * Accessed from proxy methods.
 */
class CustomSystemLogger {
	private:
		static CustomSystemLogger* logger;

		static int decorationLength;
		static char* decoration;

	public:
		CustomSystemLogger(void) {
			decorationLength = 0;
			decoration = (char*) malloc(sizeof(char) * 128);
		}
		~CustomSystemLogger(void) {
			shutdown();
		}

		static CustomSystemLogger* initialize(void) {
			if (logger == NULL) {
				logger = new CustomSystemLogger();
			}
			return logger;
		};
		static void shutdown(void) {
			delete(logger);
			logger = NULL;
		};

		//- Operations -----------------------------------=
		//
		void log_heap_allocation(const char* message) {
			printf("%s\n", message);
		};
		void log_action(const char* message) {
			printf("%s\n", message);
		};

		//- Decoration -----------------------------------=
		//
		void appendDecoration(char* dec) {
			if (logger->decorationLength < MAX_DECORATION_LENGTH) {
				sprintf(decoration, "%s%s", decoration, dec);
				logger->decorationLength++;
			}
		};
		static char* getDecoration(void) { return decoration; };
};

void log_memory(const char*);
void log_memory(const char*, bool);
void log_memory(const char*, bool, char*);
void log_action(const char*);

#endif