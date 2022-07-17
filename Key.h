#pragma once

#include <Windows.h>


void Press_two_key() {

    SHORT key;
    SHORT key2;
    UINT mappedkey;
    UINT mappedkey2;
    //in a loop

    INPUT input = { 0 };
    INPUT input2 = { 0 };
    key = VkKeyScan('i');
    key2 = VkKeyScan('p');
    //Simulating the i key

    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    /// <summary>
    /// add same code for additional button
    /// </summary>
    mappedkey2 = MapVirtualKey(LOBYTE(key2), 0);
    input2.type = INPUT_KEYBOARD;
    input2.ki.dwFlags = KEYEVENTF_SCANCODE;
    input2.ki.wScan = mappedkey2;

    SendInput(1, &input, sizeof(input));
    SendInput(1, &input2, sizeof(input2));
    /// <summary>
    /// add same code for additional button
    /// </summary>
    Sleep(20);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
    // add aditional
    input2.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input2, sizeof(input2));




}

void Press_A_key()
{
    SHORT key;
   
    UINT mappedkey;
   
    //in a loop

    INPUT input = { 0 };
    
    key = VkKeyScan('s');
    
    //Simulating the i key

    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
   
    
    SendInput(1, &input, sizeof(input));
   
    /// <summary>
    /// add same code for additional button
    /// </summary>
    Sleep(200);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
    // add aditional
   

}

void Press_i_key()
{
    SHORT key;
    UINT mappedkey;
    //in a loop

    INPUT input = { 0 };
    key = VkKeyScan('i');
    //Simulating the i key

    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(20);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));

}

void Press_o_key()
{
    SHORT key;
    UINT mappedkey;
    //in a loop

    INPUT input = { 0 };
    key = VkKeyScan('o');
    //Simulating the i key

    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(20);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));

}

void Press_p_key()
{
    SHORT key;
    UINT mappedkey;
    //in a loop

    INPUT input = { 0 };
    key = VkKeyScan('p');
    //Simulating the i key

    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(20);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));

}




void Press_any_key(char scanKey, SHORT time)
{
    SHORT key;

    UINT mappedkey;

    //in a loop

    INPUT input = { 0 };

    key = VkKeyScan(scanKey);

    //Simulating the i key

    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;


    SendInput(1, &input, sizeof(input));

    /// <summary>
    /// add same code for additional button
    /// </summary>
    Sleep(time);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
    // add aditional


}

void Press_any_two_key(char scanKey_1, char scanKey_2, SHORT time)
{
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan(scanKey_1);
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;

    // +1 k

    SHORT key2;
    UINT mappedkey2;
    INPUT input2 = { 0 };
    key2 = VkKeyScan(scanKey_2);
    mappedkey2 = MapVirtualKey(LOBYTE(key2), 0);
    input2.type = INPUT_KEYBOARD;
    input2.ki.dwFlags = KEYEVENTF_SCANCODE;
    input2.ki.wScan = mappedkey2;



    SendInput(1, &input, sizeof(input));
    SendInput(1, &input2, sizeof(input));

    Sleep(time);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
    input2.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input2, sizeof(input));
    // add aditional


}

void Press_any_three_key(char scanKey_1, char scanKey_2, char scanKey_3, SHORT time)
{
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan(scanKey_1);
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;

    // +1 k

    SHORT key2;
    UINT mappedkey2;
    INPUT input2 = { 0 };
    key2 = VkKeyScan(scanKey_2);
    mappedkey2 = MapVirtualKey(LOBYTE(key2), 0);
    input2.type = INPUT_KEYBOARD;
    input2.ki.dwFlags = KEYEVENTF_SCANCODE;
    input2.ki.wScan = mappedkey2;

    //+2

    SHORT key3;
    UINT mappedkey3;
    INPUT input3 = { 0 };
    key3 = VkKeyScan(scanKey_3);
    mappedkey3 = MapVirtualKey(LOBYTE(key3), 0);
    input3.type = INPUT_KEYBOARD;
    input3.ki.dwFlags = KEYEVENTF_SCANCODE;
    input3.ki.wScan = mappedkey3;

    SendInput(1, &input, sizeof(input));
    SendInput(1, &input2, sizeof(input));
    SendInput(1, &input3, sizeof(input));

    Sleep(time);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
    input2.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input2, sizeof(input));
    input3.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input3, sizeof(input));
    
    // add aditional


}

void Press_any_four_key(char scanKey_1, char scanKey_2, char scanKey_3, char scanKey_4, SHORT time)
{
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan(scanKey_1);
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;

    // +1 k

    SHORT key2;
    UINT mappedkey2;
    INPUT input2 = { 0 };
    key2 = VkKeyScan(scanKey_2);
    mappedkey2 = MapVirtualKey(LOBYTE(key2), 0);
    input2.type = INPUT_KEYBOARD;
    input2.ki.dwFlags = KEYEVENTF_SCANCODE;
    input2.ki.wScan = mappedkey2;

    //+2

    SHORT key3;
    UINT mappedkey3;
    INPUT input3 = { 0 };
    key3 = VkKeyScan(scanKey_3);
    mappedkey3 = MapVirtualKey(LOBYTE(key3), 0);
    input3.type = INPUT_KEYBOARD;
    input3.ki.dwFlags = KEYEVENTF_SCANCODE;
    input3.ki.wScan = mappedkey3;

    // +3

    SHORT key4;
    UINT mappedkey4;
    INPUT input4 = { 0 };
    key4 = VkKeyScan(scanKey_4);
    mappedkey4 = MapVirtualKey(LOBYTE(key4), 0);
    input4.type = INPUT_KEYBOARD;
    input4.ki.dwFlags = KEYEVENTF_SCANCODE;
    input4.ki.wScan = mappedkey4;


    SendInput(1, &input, sizeof(input));
    SendInput(1, &input2, sizeof(input));
    SendInput(1, &input3, sizeof(input));
    SendInput(1, &input4, sizeof(input));

    Sleep(time);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));

    input2.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input2, sizeof(input));

    input3.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input3, sizeof(input));

    input4.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input4, sizeof(input));

    // add aditional


}