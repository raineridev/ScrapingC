#ifndef SCRAPINGC_H
# define SCRAPINGC_H

# ifndef PORT_CHROME_WEBDRIVER
#  define PORT_CHROME_WEBDRIVER "9515"
#endif

// Includes 
#include "webdriver/chrome/commands/commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <curl/curl.h>
#include <stdarg.h>
#include <string.h>

typedef struct response {
  char		*text;
  size_t	size;
} Response;

// WebDrivers
void	chrome_init();
void	wb_init_session_url();
char	*embedf(char *source, ...);
#endif
