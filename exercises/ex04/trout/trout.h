#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>

#define MAXLINE 4096
#define BUFSIZE 1500

/* variables we might want to configure */
int max_ttl;
int nprobes;

typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;

Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;

/* other global variables */

int seq;

char recvbuf[BUFSIZE];

int sendfd, recvfd;
int pipefd[2];              /* the pipe for the alarm handler */

socklen_t salen;                    /* length of a socket address */

u_short sport;                      /* source UDP port # */
u_short dport;        /* destination port -- hopefully unused */
                                    /* 668 = the neighbor of the beast */
Timeval sendtv[1];
Timeval recvtv[1];
Timeval difftv[1];

int datalen;         /* length of the data in a datagram */

//fucntions from trout.c
void sig_alrm(int signo);
int process_ip (struct ip *ip, int len);
int recv_dgram ();
void sub_tv (Timeval *plus, Timeval *minus, Timeval *res);
double time_to_double (Timeval *time);
void print_report ();
void send_dgram (int ttl);
int send_probes (int ttl);
void loop_ttl ();
