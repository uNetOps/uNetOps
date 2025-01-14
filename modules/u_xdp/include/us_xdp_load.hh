#pragma once

struct us_xdp_load {
    us_xdp_load(){};
    int link(const char *file, const char *link, int xdp_mode);
    int unlink(const char *dev, int xdp_mode);
    int getelem(const char *mapname, void * key, void * value);
    int setelem(const char *mapname, void * key, void * value);

    char libbpf_estr[256];
#define __lbpferr__ libbpf_estr
    int progdesc;
    /* This needs to be at the end; otherwise, libbpf will write over our instance variables */
    struct bpf_object * obj;
};