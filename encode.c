#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <tables.h>

void main() {
    char *name = "Many hands make light work.";
    int s = 0, cnt=0;
    uint8_t ind;
    int len = 8 * strlen(name);
    while(s < len) {
	if(len - s < 6) {
	  printf("=");
	} else {
          if(cnt % 4 == 0) {
            printf("%s", (base64table[name[s/8] >> 2]));
	  } else if(cnt % 4 == 1) {
            printf("%s", (base64table[(name[s/8] & 0x3) << 4 | (name[s/8+1] >> 4)]));
	  } else if(cnt % 4 == 2) {
            printf("%s", (base64table[(name[s/8] & 0xF) << 2 | (name[s/8+1] >> 6)]));
	  } else if(cnt % 4 == 3) {
            printf("%s", (base64table[(name[s/8] & 0x3F)]));
	  }
	}
	s += 6;
	cnt += 1;
    }
    printf("\n");
}
