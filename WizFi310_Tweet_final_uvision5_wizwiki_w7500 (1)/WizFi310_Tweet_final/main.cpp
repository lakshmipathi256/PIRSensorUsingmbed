/*
 * Copyright (C) 2015 Wiznet, MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include "mbed.h"
#include "WizFi310Interface.h"


#define SECURE WizFi310::SEC_WPA2_MIXED
#define SSID "CDI"
#define PASS "Cdi*1717"
/*#define SSID "CDIWIZFI310TEST"
#define PASS "1234567890"*/

#if defined(TARGET_WIZwiki_W7500)
    WizFi310Interface wizfi310(D1, D0, D7, D6, D8, NC, 115200);
    Serial pc(USBTX, USBRX);
#endif


/**
 *  \brief Hello World
 *  \param none
 *  \return int
 */
int main()
{
    pc.baud(115200);
 
    printf("WizFi310  STATION. \r\n");
    wizfi310.init();
    printf("After Initialisation. \r\n");

    printf("After Set Address. \r\n");
    if ( wizfi310.connect(SECURE, SSID, PASS, WizFi310::WM_STATION))      return -1;
    printf("After Connect. \r\n");
    printf("IP Address is %s\r\n", wizfi310.getIPAddress());
    wizfi310.test_twitter();
    
    //wizfi310.disconnect();
}