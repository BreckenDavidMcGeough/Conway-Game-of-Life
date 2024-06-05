#ifndef LIFE_H_
#define LIFE_H_

/* Dimensions of the Life working area.  It should be GRIDY lines tall
 * by GRIDX characters wide when printed to the terminal, and each
 * character represents a cell. */
#define GRIDX 80
#define GRIDY 24

/* LIVE is the character value to be printed for a live cell, and DEAD
 * is the character value to be printed for a dead cell.  These values
 * are also used in the starting positions returned by parse_life(). */
#define LIVE 'X'
#define DEAD ' '

/* The documentation for these functions appears in parser.c */
char **parse_life(const char *filename);
void free_grid(char **grid);

/* Clears the terminal */
void clearterm(void);

#endif /* LIFE_H_ */
