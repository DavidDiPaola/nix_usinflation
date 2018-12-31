# 2018 David DiPaola
# licensed under CC0 (public domain, see https://creativecommons.org/publicdomain/zero/1.0/)

BIN = usinflation

.PHONY: all
all: $(BIN)

data.h: data.txt
	python3 data_process.py > data.h

main.c: data.h

$(BIN): main.c
	$(CC) -Wall -Wextra -O2 $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(BIN) data.h

