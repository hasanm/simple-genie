#ifndef SIMPLE_H
#define SIMPLE_H

#ifdef __cplusplus
extern "C" {
#endif
    char* get_machine();
    int load_dat(void* container, char *filename);

#ifdef __cplusplus
}
#endif

#endif
