/* Assignment:
 * “Write a program to control a bread machine. Allow the user to input the
 * type of bread as W for White, and S for Sweet. Ask the user if the loaf size
 * is double, and if the baking is manual. The following table details the time
 * chart for the machine for each bread type. Display a statement for each
 * step. If the loaf size is double, increase the baking time by 50 percent. If
 * baking is manual, stop after the loaf-shaping cycle and instruct the user to
 * remove the dough for manual baking. Use functions to display instructions to
 * the user and to compute the baking time."
 * 
 * The basic plan is to have each step be its own function, whose first two
 * parameters are the running duration in minutes and seconds. The next parameters
 * are the bread_type and/or loaf_size, since these affect the step duration.
 * 
 * Post-conditions enforce the contract that each step is exactly as long as
 * specified.
 */
#include <stdio.h>
#include <assert.h>

/* common predicates which don't merit their own functions, but appear frequently */
#define is_white(x) (('w' == (x)) || ('W' == (x)))
#define is_sweet(x) (('s' == (x)) || ('S' == (x)))
#define is_single(x) (('s' == (x)) || ('S' == (x)))
#define is_double(x) (('d' == (x)) || ('D' == (x)))
#define is_manual(x) (('y' == (x)) || ('Y' == (x)))
#define is_automatic(x) (('n' == (x)) || ('N' == (x)))
/* macros to clarify which parameters are just "input" and which store "outputs" */
#define IN 
#define OUT 

void primary_kneading_time(OUT int *minutes, OUT int *seconds, IN char bread_type) {
	int duration_minutes = 15 + is_sweet(bread_type)*5;
	printf("Primary kneading: %d minutes\n", duration_minutes);
	(*minutes) += duration_minutes;
	assert((is_white(bread_type) && (15 == duration_minutes))
	       || (is_sweet(bread_type) && (20 == duration_minutes)));
}

void primary_rising_time(OUT int *minutes, OUT int *seconds) {
	int duration_minutes = 60;
	printf("Primary rising: %d minutes\n", duration_minutes);
	(*minutes) += duration_minutes;
}

void secondary_kneading_time(OUT int *minutes, OUT int *seconds, IN char bread_type) {
	int duration_minutes = 18 + is_sweet(bread_type)*15;
	printf("Secondary kneading: %d minutes\n", duration_minutes);
	(*minutes) += duration_minutes;
	assert((is_white(bread_type) && (18 == duration_minutes))
	       || (is_sweet(bread_type) && (33 == duration_minutes)));
}

void secondary_rising_time(OUT int *minutes, OUT int *seconds, IN char bread_type) {
	int duration_minutes = 20 + is_sweet(bread_type)*10;
	printf("Secondary rising: %d minutes\n", duration_minutes);
	(*minutes) += duration_minutes;
	assert((is_white(bread_type) && (20 == duration_minutes))
	       || (is_sweet(bread_type) && (30 == duration_minutes)));
}

void loaf_shaping_time(OUT int *minutes, OUT int *seconds) {
	printf("Loaf shaping: 2 seconds\n");
	(*seconds) += 2;
}

void final_rising_time(OUT int *minutes, OUT int *seconds) {
	int duration_minutes = 75;
	printf("Final rising: %d minutes\n", duration_minutes);
	(*minutes) += duration_minutes;
}

void baking_time(OUT int *minutes, OUT int *seconds, IN char bread_type, IN char loaf_size) {
	int duration_seconds = (is_double(loaf_size)*30);
	int duration_minutes = 35 + is_double(loaf_size)*17 + is_white(bread_type)*(10 + is_double(loaf_size)*5);
	printf("Baking: %d minutes %d seconds\n", duration_minutes, duration_seconds);
	(*minutes) += duration_minutes;
	(*seconds) += duration_seconds;
	assert((is_white(bread_type) && is_double(loaf_size) && ((45/2) + 45 == duration_minutes))
	       || (is_white(bread_type) && !is_double(loaf_size) && (45 == duration_minutes))
	       || (is_sweet(bread_type) && is_double(loaf_size) && ((35/2) + 35 == duration_minutes))
	       || (is_white(bread_type) && !is_double(loaf_size) && (35 == duration_minutes)));
	assert((is_double(loaf_size) && (30 == duration_seconds))
			|| (is_single(loaf_size) && (0 == duration_seconds)));
}

void cooling_time(OUT int *minutes, OUT int *seconds) {
	int duration_minutes = 30;
	printf("Cooling: %d minutes\n", duration_minutes);
	(*minutes) += duration_minutes;
}

void calc_baking_time(IN char bread_type, IN char loaf_size, IN char manual) {
	int minutes = 0;
	int seconds = 0;
	primary_kneading_time(&minutes, &seconds, bread_type);
	primary_rising_time(&minutes, &seconds);
	secondary_kneading_time(&minutes, &seconds, bread_type);
	secondary_rising_time(&minutes, &seconds, bread_type);
	loaf_shaping_time(&minutes, &seconds);
	
	
	if (is_manual(manual)) {
		printf("You should remove the dough for manual baking.\n");
	} else {
		final_rising_time(&minutes, &seconds);
		baking_time(&minutes, &seconds, bread_type, loaf_size);
		cooling_time(&minutes, &seconds);
	}
	printf("\nFor a total baking time of %d minutes and %d seconds.\n", minutes, seconds);
}

void read_bread_type(OUT char *bread_type) {
	printf("Are you making white or sweet bread (w or s)? ");
	scanf("%c", bread_type);
	assert(is_sweet(*bread_type) || is_white(*bread_type));
}

void read_loaf_size(OUT char *loaf_size) {
	printf("Is this a single or double loaf (s or d)? ");
	scanf(" %c", loaf_size);
	assert(is_single(*loaf_size) || is_double(*loaf_size));
}

void read_manual(OUT char *manual) {
	printf("Are you going to bake manually (y or n)? ");
	scanf(" %c", manual);
	assert(is_manual(*manual) || is_automatic(*manual));
}

void display_instructions(OUT char *bread_type, OUT char *loaf_size, OUT char *manual) {
	read_bread_type(bread_type);
	read_loaf_size(loaf_size);
	read_manual(manual);
}

int main() {
	char bread_type, loaf_size, manual;
	display_instructions(&bread_type, &loaf_size, &manual);
	calc_baking_time(bread_type, loaf_size, manual);
	return 0;
}
