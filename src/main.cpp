#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#include "logger.h"
#include "launcher.h"

bool g_verbose = false;
bool g_echo = false;
bool g_log_memory = false;
bool g_log_game = false;

int main(int argc, char** argv) {

	//- Argument Extraction ------------------------------=
	//
	int opt;
	while ((opt = getopt(argc, argv, "ve")) != -1) {
		switch(opt) {
			case 'v':
				printf("\\> [Verbose Mode]\n");
				g_verbose = true;
				g_log_memory = true;
				g_log_game = true;
				break;
			case 'e':
				printf("\\> [Echo Mode]\n");
				g_echo = true;
				break;
			default:
				// You're drunk. Get help.
				printf("Usage: -p [port] | -r [relayhost:port] | -R [path]\n");
				return EXIT_SUCCESS;
		}
	}

	launchGame();

	return EXIT_SUCCESS;
}

