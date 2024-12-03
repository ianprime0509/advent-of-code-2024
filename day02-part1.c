#include <sys/types.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool is_safe(char *line) {
    int previous_level = -1;
    int previous_direction = 0;
    char *token = NULL;
    char *saveptr = NULL;
    while ((token = strtok_r(token == NULL ? line : NULL, " ", &saveptr)) != NULL) {
        int level = atoi(token);
        if (previous_level != -1) {
            int current_direction = level >= previous_level ? 1 : -1;
            if (previous_direction != 0 && current_direction != previous_direction) {
                return false;
            }
            previous_direction = current_direction;
            int diff_level = abs(level - previous_level);
            if (diff_level < 1 || diff_level > 3) {
                return false;
            }
        }
        previous_level = level;
    }
    return true;
}

int main(void) {
    FILE *input = fopen("day02.txt", "r");
    if (input == NULL) {
        perror("open: ");
        return 1;
    }

    int exit_code = 0;
    int n_safe = 0;
    char *line_buf = NULL;
    size_t line_buf_len = 0;
    for (;;) {
        ssize_t line_len = getline(&line_buf, &line_buf_len, input);
        if (line_len < 0) {
            if (errno == 0) {
                break;
            }
            perror("read: ");
            exit_code = 1;
            goto exit;
        }
        if (is_safe(line_buf)) {
            n_safe++;
        }
    }
    printf("%d\n", n_safe);
exit:
    free(line_buf);
    fclose(input);
    return exit_code;
}
