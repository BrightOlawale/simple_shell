#ifndef OSH_H
#define OSH_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER 1024
#define TRUE 1
#define PROMPT "Osh $ "
/* error strings */
#define ERR_MALLOC "Unable to allocate memory\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;
/**
 * struct list_s - linked list of variables
 * @value: value
 * @next: pointer to nextnode
 *
 * Description: generic linked list struct for variables.
**/
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 * Description: struct for builtin functions.
**/

typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

void prompt(int fd, struct stat buf);
char *_getline(FILE *fp);
char **tokenizer(char *str);
char *_which(char *command, char *fullpath, char *path);
int child(char *fullpath, char **tokens);
void errors(int error);

/*utility library */
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);

/* prototypes for builtins */
int shell_env(void);
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_num_builtins(built_s builtin[]);

/* prototypes for the helper functions for path linked list */
char *_getenv(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
list_s *pathlist(char *variable, list_s *head);

int cd_path(char *dir, cmd_t *cmd);
int cd_home(cmd_t *cmd);
int cd_back(cmd_t *cmd);
int cd_curr(cmd_t *cmd);
int cd_parent(cmd_t *cmd);
char *swap_char(char *input, int bool);
void add_nodes(sep_t **head_s, line_t **head_l, char *input);
void go_next(sep_t **list_s, line_t **list_l, cmd_t *cmd);
int apply_seperators(cmd_t *cmd, char *input);



/* prototypes for free functions */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_dp(char **array, unsigned int length);

#endif /* OSH_H*/
