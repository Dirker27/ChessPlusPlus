#ifndef LOGGER_H
#define LOGGER_H

#include <stdbool.h>

extern bool g_log_memory;
extern bool g_log_game;

void log_memory(const char*, bool);
void log_action(const char*);

#endif