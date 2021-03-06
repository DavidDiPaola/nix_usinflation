/*
2018 David DiPaola
licensed under CC0 (public domain, see https://creativecommons.org/publicdomain/zero/1.0/)
*/

#include <stdio.h>

#include <stdlib.h>

#include "data.h"

int
main(int argc, char * argv[]) {
	if (argc < 4) {
		fprintf(stderr, "syntax: usinflation <start year> <start amount> <end year>" "\n");
		return 1;
	}
	int   start_year   = atoi(argv[1]);
	float start_amount = (float)atof(argv[2]);
	int   end_year     = atoi(argv[3]);

	if ((start_year < DATA_STARTYEAR) || (start_year > DATA_ENDYEAR)) {
		fprintf(stderr, "ERROR: start year: %i is invalid. valid years are %i-%i" "\n", start_year, DATA_STARTYEAR, DATA_ENDYEAR);
		return 2;
	}
	if ((end_year < DATA_STARTYEAR) || (end_year > DATA_ENDYEAR)) {
		fprintf(stderr, "ERROR: end year: %i is invalid. valid years are %i-%i" "\n", end_year, DATA_STARTYEAR, DATA_ENDYEAR);
		return 3;
	}

	float ratio = DATA[end_year-DATA_STARTYEAR] / DATA[start_year-DATA_STARTYEAR];
	float end_amount = ratio * start_amount;
	printf("%G" "\n", end_amount);
	return 0;
}

