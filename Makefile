FILES := *.c webdriver/chrome/*.c webdriver/chrome/commands/*.c
CFLAGS := -Wall -Wextra -Werror
FLAGS := -lcurl
all: 
	gcc $(FILES) $(FLAGS) -o scrapingc 