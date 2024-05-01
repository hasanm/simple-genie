#ifndef SIMPLE_H
#define SIMPLE_H

#ifdef __cplusplus
extern "C" {
#endif
    char* get_machine();
    void* load_dat(char *filename);
    int print_all(void* ptr);
    int get_unit(void* ptr, char *unit_name);

#ifdef __cplusplus
}
#endif

#endif
