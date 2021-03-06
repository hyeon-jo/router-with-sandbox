#ifndef __PKTCHECK_H__

#define __PKTCHECK_H__

#include <pthread.h>
#include "def.h"

int check_packet(int o, int s, const struct pcap_pkthdr *h, u_char *p);
void hexdump(const void* data, size_t size);
void parse_http_header(char **url, char **cookie, char *data);
int32_t JumpConsistentHash(uint64_t key, int32_t num_buckets);

struct pkt_set_t {
    struct pcap_pkthdr *h;
    u_char *p;
    struct pkt_set_t *next;
};

// int uniq_id;
struct http_request_t {
    struct pkt_set_t *pkt;
    struct pkt_set_t *pkt_last;
    int o;
    int s;
    u_char *msg;
};

#define HTTP_REQ_HT_SIZE 1024

#endif
