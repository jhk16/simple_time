#include <stdio.h>
#include <time.h>

#define BUFFER 10000000

void task() {
	int i = BUFFER;
	while (i--) { }
}

int main(void) {

	struct timespec start_timestamp;
	struct timespec end_timestamp;

	long long elapsed_time_ns;

	int err = 0;

	clock_gettime(CLOCK_MONOTONIC, &start_timestamp);
	// some_task() ...
	task();
	clock_gettime(CLOCK_MONOTONIC, &end_timestamp);


	end_timestamp.tv_sec - start_timestamp.tv_sec;
	end_timestamp.tv_nsec - start_timestamp.tv_nsec;

	elapsed_time_ns =
		(end_timestamp.tv_sec - start_timestamp.tv_sec) * 1000000000
		+ (end_timestamp.tv_nsec - start_timestamp.tv_nsec);

	printf("elapsed time(ns):%llu\n", elapsed_time_ns);

	return 0;
}
