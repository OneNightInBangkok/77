

#include <Windows.h> 
#include <iostream>
#include "Key.h"
#include <TlHelp32.h>
#include "combo.h"
#include "DirectOverlay.h"


    DWORD GetProcId(const wchar_t* procName)
    {
        DWORD procId = 0;
        HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

        if (hSnap != INVALID_HANDLE_VALUE)
        {

            PROCESSENTRY32 procEntry;
            procEntry.dwSize = sizeof(procEntry);

            if (Process32First(hSnap, &procEntry))
            {
                do
                {
                    if (!_wcsicmp(procEntry.szExeFile, procName))

                    {

                        procId = procEntry.th32ProcessID;
                        break;
                    }


                } while (Process32Next(hSnap, &procEntry));


            }


        }

        CloseHandle(hSnap);
        return procId;

    }


    uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName)
    {
        uintptr_t modBaseAddr = 0;
        HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
        if (hSnap != INVALID_HANDLE_VALUE)
        {

            MODULEENTRY32 modEntry;
            modEntry.dwSize = sizeof(modEntry);
            if (Module32First(hSnap, &modEntry))
            {
                do
                {

                    if (!_wcsicmp(modEntry.szModule, modName))
                    {

                        modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
                        break;


                    }


                } while (Module32Next(hSnap, &modEntry));

            }

        }
        CloseHandle(hSnap);
        return modBaseAddr;
    }

   float inp_buff;
    int Data = 0;
    unsigned int ammoValue;
  unsigned  int p1Value;
    long long adress = 0x7FF62AD3AB68;
    
    float d6 = 1600.00000;
    float d26 = 2600.00000;
    float dd = 2000.00000;
    float d18 = 1800.00000;
    float dm = 3000.00000;
    float inp_buff2;
    int buff_input_address_1;
    int buff_input_address_2;


    void laine()
    {

        AllocConsole();
        freopen("CONOUT$", "w", stdout);

        int ikarus;
        int frame_all = 0x34E7C40;
        int frame_P1 = 0x34E73A4;
        int frame_P2 = 0x34EABDC;
        int P1_move_id = 0x34E7520;
        int P2_move_id = 0x34EAB90;
        int P1_stun = 0x34E75FC;
        int P2_stun = 0x34EAC6C;
        int is_right_side_p1 = 0x34E869C;
        int r_foot = 0x800;
        int l_foot = 0x1000;
        bool crouch = true;
        bool my_storona = false;
        bool block = true;
        bool throw_on = true;
        bool low_on = true;
        bool step_on = false;
        bool step = false;
        bool punish = true;
        bool lwhit = false;
        bool p1 = true;
        bool ready = true;
        bool side = true;
        float distance = 0;   // dont work.  
        float distance2 = 0;
        int time_to_delay = 100;
        unsigned int high = 0xA000050F;
        unsigned int mid = 0x8000020A;
        int low = 0x20000112;
        int inp_right = 0x400;
        int inp_left = 0x200;
        int input_p1 = 0x34E8C2C;
        int input_p2 = 0x34EC29C;
        int throw_4 = 0xF000001E;                  // значение  наказания
        int throw_1 = 0xD000001C;
        int throw_5 = 0xE000001F;
        int throw_value_p1;          // буффер для значения
        int throw_value_p2;
        int buffer_move_state_p2;
        int buffer_move_state_p1;
        int buffer_right_side;
        int p1_block = 0x34E79A8;
        int p2_block = 0x34EB018;
        int block_buffer;
        int stun_buffer_1;
        int stun_buffer_2;
        int move_id_buffer_p1;
        int move_id_buffer_p2;
        int buffer_frame_all;
        int buffer_frame_P1;
        int buffer_frame_P2;

        uintptr_t simple_move_state_p2 = 0x34EAC68;
        uintptr_t simple_move_state_p1 = 0x34E75F8;
        uintptr_t throw_p1_address = 0x34E7620;   // адресс для динамического значения throw
        uintptr_t throw_p2_address = 0x34EAC90;
        uintptr_t adress_distance = 0x34DD480;
        uintptr_t attackType = 0x34EAB68;
        uintptr_t attackType_P1 = 0x34E74F8;
        uintptr_t adress_distance_second = 0x34E8620;
        uintptr_t adress_input_p1;
        uintptr_t adress_input_p2;


        DWORD procId = GetProcId(L"TekkenGame-Win64-Shipping.exe");
        uintptr_t moduleBase = GetModuleBaseAddress(procId, L"TekkenGame-Win64-Shipping.exe");



        uintptr_t adress_frame_all = moduleBase + frame_all;
        uintptr_t adress_frame_P1 = moduleBase + frame_P1;
        uintptr_t adress_frame_P2 = moduleBase + frame_P2;
        uintptr_t adress_move_id_P1 = moduleBase + P1_move_id;
        uintptr_t adress_move_id_P2 = moduleBase + P2_move_id;
        uintptr_t adress_stun_p1 = moduleBase + P1_stun;
        uintptr_t adress_stun_p2 = moduleBase + P2_stun;
        uintptr_t adress_block_p1 = moduleBase + p1_block;
        uintptr_t adress_block_p2 = moduleBase + p2_block;
        uintptr_t adress_is_right_side_p1 = moduleBase + is_right_side_p1;
        uintptr_t adress_move_state_p2 = moduleBase + simple_move_state_p2;
        uintptr_t adress_move_state_p1 = moduleBase + simple_move_state_p1;

        uintptr_t attackaddress = moduleBase + attackType;
        
        uintptr_t attackaddress_P1 = moduleBase + attackType_P1;                                          //ATTACK P1
        

        uintptr_t true_address_distance = moduleBase + adress_distance;
       
        uintptr_t second_true_address_distance = moduleBase + adress_distance_second;
        

        uintptr_t throw_p1 = moduleBase + throw_p1_address;                                               // адресс чтение throw 1
        
        uintptr_t throw_p2 = moduleBase + throw_p2_address;                                               // адресс чтение throw 2
        

        adress_input_p1 = moduleBase + input_p1;
        

        adress_input_p2 = moduleBase + input_p2;
       

        HWND WindowHandle = FindWindow(nullptr, L"TEKKEN 7 ");             // useless cod, because i have GetProcId
        DWORD PID = 0;                                                      // I left this here because I'm too lazy to fix it

        GetWindowThreadProcessId(WindowHandle, &PID);
        HANDLE hProcess = 0;                                            // Изменил Lpvoid на HANDLE
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, PID);


        while (1) {


            if (GetAsyncKeyState(0x20)) {     //   0x20	Space key


                if (side == true) {
                    bdc();
                }

                if (side == false) {

                    bdc_right();
                }

            }


            if (GetAsyncKeyState(0x52)) 
            {     //  	0x45	E key

               
                if (side == true) {
                    Press_any_key('d', 17);
                    Sleep(17);
                    Press_any_key('s', 17);
                    Press_any_two_key('d', 's', 17);
                    Press_any_four_key('d', 's', 'o', 'p', 17);
                }

                if (side == false) {
                    Press_any_key('d', 17);
                    Sleep(17);
                    Press_any_key('s', 17);
                    Press_any_two_key('d', 's', 17);
                    Press_any_four_key('d', 's', 'o', 'p', 17);

                 
                }

                king_bridge();


            }
            
               


            if (GetAsyncKeyState(0x35)) {     //   0x35	5 key
                
                
                crouch = !crouch;
                std::cout << "crouch = " << crouch << std::endl;
                Sleep(200);
            }

            //////

            if (GetAsyncKeyState(0x31)) {     //   0x31	1 key

                low_on = !low_on;
                std::cout << "Low_on = " << low_on << std::endl;
                Sleep(200);
            }

            if (GetAsyncKeyState(0x32)) {     //   0x32	2 key

                throw_on = !throw_on;
                std::cout << "throw_on = " << throw_on << std::endl;
                Sleep(200);
            }

            if (GetAsyncKeyState(0x33)) {     //   0x33	3 key

                block = !block;
                std::cout << "Block on/off = " << block << std::endl;
                Sleep(200);
            }



            

            if (GetAsyncKeyState(0x45)) {     //  	0x52	R key

                if (side == true) {
                    swift();
                }

                if (side == false) {

                    swift_right();
                }

            }

            if (GetAsyncKeyState(0x46)) {     //  0x46	F key

                if (side == true) {
                    cat_foot();
                }

                if (side == false) {

                    cat_foot_right();
                }

            }

            if (GetAsyncKeyState(0x51)) {     //  0x51	Q key

                if (side == true) {
                    fury();
                            
                        }

                        if (side == false) {
                            fury_right();
                            
                        }

                       

            }

            if (GetAsyncKeyState(0x4A)) {     // 0x4A	J key

                step_on = !step_on;
                std::cout << "move_state = " << step_on << std::endl;
                Sleep(200);
            }
            

            if (GetAsyncKeyState(0x34)) {     //    0x34	4 key

          // ikaruga(); 0x5A	Z key
          // soul_stealer();
                punish = !punish;
                std::cout << "punish = " << punish << std::endl;
                Sleep(200);
            }

            if (GetAsyncKeyState(0x58)) {     //  0x58	X key

           // ikaruga(); 0x5A	Z key
           // soul_stealer();
                side = !side;
                std::cout << "side = " << side << std::endl;
                Sleep(200);
            }


            if (GetAsyncKeyState(0x48)) {   // 0x48	H key

                lwhit = !lwhit;

                std::cout << "lwhit = " <<lwhit <<std::endl;
                
                Sleep(200);
            }

            if (GetAsyncKeyState(0x47)) {    // g key

                p1 = !p1;
                std::cout << "p1 = " << p1 << std::endl;
                
                Sleep(200);
            }

            if (GetAsyncKeyState(0x39)) {    // 39 - 9 key     46 F

                ready = !ready;
                std::cout << "ready = " << ready << std::endl;
                
                Sleep(200);
            }

            if (ready == true) {

                if (p1 == true) {
                    ReadProcessMemory(hProcess, (LPCVOID)attackaddress, &ammoValue, sizeof(ammoValue), nullptr); // x32 выдает ошибку 12b. Сборка только в x64
                    ReadProcessMemory(hProcess, (LPCVOID)throw_p1, &throw_value_p1, sizeof(throw_value_p1), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID)second_true_address_distance, &inp_buff, sizeof(inp_buff), nullptr); 
                    ReadProcessMemory(hProcess, (LPCVOID)adress_input_p2, &buff_input_address_2, sizeof(buff_input_address_2), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p2, &buffer_move_state_p2, sizeof(buffer_move_state_p2), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID)adress_block_p1, &block_buffer, sizeof(block_buffer), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID)adress_stun_p2, &stun_buffer_2, sizeof(stun_buffer_2), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID)adress_stun_p1, &stun_buffer_1, sizeof(stun_buffer_1), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID)adress_move_id_P2, &move_id_buffer_p2, sizeof(move_id_buffer_p2), nullptr);

                    ReadProcessMemory(hProcess, (LPCVOID)adress_move_id_P2, &move_id_buffer_p2, sizeof(move_id_buffer_p2), nullptr);

                    ReadProcessMemory(hProcess, (LPCVOID)adress_frame_all, &buffer_frame_all, sizeof(buffer_frame_all), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID)adress_frame_P1, &buffer_frame_P1, sizeof(buffer_frame_P2), nullptr);
                    
                   // std::cout << "move_id_buffer = " << move_id_buffer << std::endl;
                   /* std::cout << "buffer_frame_P1 = " << buffer_frame_P1 << std::endl;
                    std::cout << "buffer_frame_all = " << buffer_frame_all << std::endl;*/

                  /*  if (stun_buffer_1 == 0x100 && buffer_frame_P1 == 1)
                    {
                        ReadProcessMemory(hProcess, (LPCVOID)adress_frame_all, &buffer_frame_all, sizeof(buffer_frame_all), nullptr);

                        ikarus = buffer_frame_all;
                        Sleep(17);
                        ReadProcessMemory(hProcess, (LPCVOID)adress_frame_all, &buffer_frame_all, sizeof(buffer_frame_all), nullptr);
                        while (buffer_frame_P1 != 1)
                        {

                            ReadProcessMemory(hProcess, (LPCVOID)adress_frame_P1, &buffer_frame_P1, sizeof(buffer_frame_P2), nullptr);
                        }

                        ReadProcessMemory(hProcess, (LPCVOID)adress_frame_all, &buffer_frame_all, sizeof(buffer_frame_all), nullptr);

                        ikarus = buffer_frame_all - ikarus;
                        std::cout << "ikarus = " << ikarus << std::endl;
                    }*/

                    








                    //if (move_id_buffer == 1573)
                    //{
                    //    std::cout << "do move_id_buffer = " << move_id_buffer << std::endl;
                    //    Press_any_key('w', 17);
                    //    Sleep(67);
                    //    std::cout << "posle move_id_buffer = " << move_id_buffer << std::endl;
                    //    Press_any_key('w', 100);
                    //    std::cout << "last move_id_buffer = " << move_id_buffer << std::endl;


                    //   /* ReadProcessMemory(hProcess, (LPCVOID)adress_move_id_P2, &move_id_buffer, sizeof(move_id_buffer), nullptr);
                    //    std::cout << "move_id_buffer = " << move_id_buffer << std::endl;
                    //    if (move_id_buffer == 1575)
                    //    {
                    //        std::cout << " 1575 move_id_buffer = " << move_id_buffer << std::endl;
                    //        Press_any_key('s', 170);
                    //        Sleep(17);
                    //        Press_any_key('p', 17);
                    //        Sleep(200);

                    //    }

                    //    if (move_id_buffer == 1573 || move_id_buffer == 1576)
                    //    {
                    //        std::cout << "1573 1576 move_id_buffer = " << move_id_buffer << std::endl;
                    //        Press_any_key('k', 17);
                    //        Sleep(200);

                    //    }*/



                    //}


                    if (crouch == true && inp_buff <= dd)
                    {
                        if (buffer_move_state_p2 == 0x5 || buffer_move_state_p2 == 0x6 || buffer_move_state_p2 == 0x7)
                        {
                            ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p1, &buffer_move_state_p1, sizeof(buffer_move_state_p1), nullptr);
                            if (buffer_move_state_p1 == 0x3)
                            {
                                if (side == true) {
                                    noga(); 

                                }

                                if (side == false) {
                                    noga2();

                                }
                            }

                        }


                    }

                  /*  if (move_id_buffer == 1573 && (inp_buff <= d26 && inp_buff >= d6))
                    {

                      
                        Press_any_four_key('d', 'w', 'i', 'p', 17);
                        Sleep(200);
                    }

                    if (move_id_buffer == 1573 && (inp_buff <= d26 && inp_buff >= d6))
                    {

                        side_step_l_kick();
                        std::cout << "P1_move_id_buffer = " << move_id_buffer << std::endl;
                    }*/

                   


                    //std::cout << "stun_buffer = " << stun_buffer << std::endl;

                    if (GetAsyncKeyState(0x60))
                    {    //VK_NUMPAD0	0x60	Numeric keypad 0 key
                       
                            Press_any_three_key('d', 'i', 'p', 17);

                            Sleep(382);
                            ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p2, &buffer_move_state_p2, sizeof(buffer_move_state_p2), nullptr);
                           // std::cout << "stun_buffer = " << buffer_move_state_p2 << std::endl;

                            if (buffer_move_state_p2 != 0x2 && buffer_move_state_p2 != 0x3 ) {
                               // std::cout << "stun_buffer = " << buffer_move_state_p2 << std::endl;

                                Press_any_key('o', 17);
                                ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p2, &buffer_move_state_p2, sizeof(buffer_move_state_p2), nullptr);
                                if (buffer_move_state_p2 != 0x2) {

                                    Sleep(250);
                                    Press_any_key('p', 17);
                                    Sleep(250);
                                    Press_any_key('i', 17);
                                    Sleep(100);

                                }


                            }

                        


                    }


                    
                    if (GetAsyncKeyState(0x5A)) {     //     0x5A	Z key


                        if (side == true) {
                            Press_any_three_key('d', 'k', 'o', 17);
                        }

                        if (side == false) {
                            Press_any_three_key('a', 'k', 'o', 17);
                            
                        }
                        
                        Sleep(150);  // 260 summary
                        ReadProcessMemory(hProcess, (LPCVOID)attackaddress, &ammoValue, sizeof(ammoValue), nullptr);
                        if (ammoValue != high && ammoValue != mid && ammoValue != low)
                        {
                            Sleep(109);  //  260 - 150   = 110 



                            if (side == true) {
                                Press_any_key('d', 17);
                            }

                            if (side == false) {
                                
                                Press_any_key('a', 17);
                            }


                            
                            Sleep(280);
                            ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p2, &buffer_move_state_p2, sizeof(buffer_move_state_p2), nullptr);
                            ReadProcessMemory(hProcess, (LPCVOID)second_true_address_distance, &inp_buff, sizeof(inp_buff), nullptr);
                              // 280 
                            if (inp_buff <= dd && buffer_move_state_p2 != 0x5 && buffer_move_state_p2 != 0x6 && buffer_move_state_p2 != 0x7)
                            {
                                Press_any_two_key('i', 'p', 17);
                                

                            }

                            if (inp_buff <= dd && buffer_move_state_p2 == 0x5 || buffer_move_state_p2 == 0x6 || buffer_move_state_p2 == 0x7)
                            {
                                Press_any_key('i', 17);


                            }
                            
                            

                        }
                       
                        if (ammoValue == high || ammoValue == mid || ammoValue == low)
                        {

                            if (side == true) {
                                Press_any_key('a', 17);
                            }

                            if (side == false) {

                                Press_any_key('d', 17);
                            }
                            


                        }





                    }


                    



                    if (block == true) {

                        if (ammoValue == high && inp_buff < dd && (buff_input_address_2 == 0xA00 || buff_input_address_2 == 0x1400)) {

                            jeb_zahvat();
                           // noga();

                        }


                    }


                    //
                       
                            

                        if (punish == true) {

                            if (ammoValue == high && inp_buff < d18 ) 
                            {
                                ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p1, &buffer_move_state_p1, sizeof(buffer_move_state_p1), nullptr);

                                if (buffer_move_state_p1 == 0x3)
                                {
                                    if (ammoValue == high && inp_buff < d18 && (buff_input_address_2 == 0x200 || buff_input_address_2 == 0x400)) {

                                        Press_any_key('s', 117);
                                        
                                        Press_any_two_key('i', 'k', 17);

                                    }
                                }
                            }

                        }
                       
                    
                    
                    

                        if (step_on == true) 
                        {
                            

                                
                                if (buffer_move_state_p1 == 0x3)
                                {   
                                    



                                    if (inp_buff <= d26)
                                    {

                                        ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p1, &buffer_move_state_p1, sizeof(buffer_move_state_p1), nullptr);

                                        //jin start
                                        if (move_id_buffer_p2 == 1552)
                                        {
                                            side_step_w();
                                        }

                                        if (move_id_buffer_p2 == 1606)
                                        {
                                            side_step_s();
                                        }
                                        //jin end
                                        //noctis start
                                       /* if (move_id_buffer_p2 == 1621)
                                        {
                                            side_step_s();

                                        }*/

                                         //noctis end

                                    }

                                    //
                                     if (move_id_buffer_p2 == 1535)
                                        {
                                         if(inp_buff <=dd)
                                         { 
                                            side_step_w();
                                         }
                                        }

                                   
                                            
                                     if (move_id_buffer_p2 == 1636 || move_id_buffer_p2 == 1637)
                                     {
                                         if (inp_buff <= dd)
                                         {
                                         
                                         side_step_w();
                                        }
                                     }


                                   

                                }


                                if (buffer_move_state_p2 == 0x1)
                                {

                                    if ( inp_buff <= dd)
                                    {

                                        ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p1, &buffer_move_state_p1, sizeof(buffer_move_state_p1), nullptr);
                                        //noctis start

                                       /*if (move_id_buffer_p2 == 1474)
                                       {
                                           Press_any_key('w', 17);
                                           Sleep(166);
                                           Press_any_key('s', 17);
                                           Sleep(166);
                                           Press_any_key('s', 166);
                                       }

                                       if (move_id_buffer_p2 == 1489)
                                       {
                                           side_step_s();
                                       }*/
                                        if (move_id_buffer_p2 == 1476)
                                        {
                                            Sleep(85);
                                            jeb_fast();
                                            std::cout << "move_id_buffer_p2 = " << move_id_buffer_p2 << std::endl;
                                        }

                                        if (move_id_buffer_p2 == 1477)
                                        {
                                            Sleep(85);
                                            Press_any_key('w', 17);
                                            std::cout << "move_id_buffer_p2 = " << move_id_buffer_p2 << std::endl;
                                            Sleep(177);
                                        }


                                        if (move_id_buffer_p2 == 1618)
                                        {
                                            jeb_fast();

                                        }

                                        if (move_id_buffer_p2 == 1630)
                                        {
                                            jeb_fast();

                                        }


                                        //noctis end

                                    }

                                }

                            

                        }





                    if (low_on == true) {
                        /// <summary>
                       //sadasdadad
                        /// </summary>
                        if (ammoValue == low && inp_buff < dd) {
                            if (lwhit == true) {
                                if (side == true) {
                                    for (int i = 0; i <= 16; i++) {
                                        Press_any_two_key('s', 'd', 16);
                                    }

                                }
                                ////////////////////////////////
                                if (side == false) {
                                    for (int i = 0; i <= 16; i++) {
                                        Press_any_two_key('s', 'a', 16);
                                    }

                                }
                            }
                            if (lwhit == false) {
                                if (side == true) {
                                    noga();
                                }
                            
                            ////////////////////////////////
                            if (side == false) {
                                noga2();
                            }

                            }

                        }
                        ///**
                    }

                    if (throw_on == true) {
                        if (throw_value_p1 == throw_1 || throw_4 || throw_5) {


                            if (throw_value_p1 == throw_1) {

                                // throw 1
                                Press_i_key();


                            }

                            if (throw_value_p1 == throw_4) {

                                // throw 4
                                Press_two_key();

                            }

                            if (throw_value_p1 == throw_5) {

                                // throw 5
                                Press_p_key();

                            }


                        }
                    }

                }

                if (p1 == false) {

                    ReadProcessMemory(hProcess, (LPCVOID*)attackaddress_P1, &p1Value, sizeof(p1Value), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID*)throw_p2, &throw_value_p2, sizeof(throw_value_p2), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID*)second_true_address_distance, &inp_buff2, sizeof(inp_buff2), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID)adress_input_p1, &buff_input_address_1, sizeof(buff_input_address_1), nullptr);
                    //ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p1, &buffer_move_state_p1, sizeof(buffer_move_state_p1), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID)adress_block_p2, &block_buffer, sizeof(block_buffer), nullptr);
                    ReadProcessMemory(hProcess, (LPCVOID)adress_move_id_P1, &move_id_buffer_p1, sizeof(move_id_buffer_p1), nullptr);

                    if (crouch == true && inp_buff2 <= dd)
                    {
                        if (buffer_move_state_p1 == 0x5 || buffer_move_state_p1 == 0x6 || buffer_move_state_p1 == 0x7)
                        {
                            ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p2, &buffer_move_state_p2, sizeof(buffer_move_state_p2), nullptr);
                            if (buffer_move_state_p2 == 0x3)
                            {
                                if (side == true) {
                                    noga();

                                }

                                if (side == false) {
                                    noga2();

                                }
                            }

                        }


                    }


                    
                    if (GetAsyncKeyState(0x60))
                    {    //VK_NUMPAD0	0x60	Numeric keypad 0 key
                        
                            Press_any_three_key('d', 'i', 'p', 17);

                            Sleep(382);
                            ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p1, &buffer_move_state_p1, sizeof(buffer_move_state_p1), nullptr);
                           // std::cout << "stun_buffer = " << buffer_move_state_p1 << std::endl;

                            if (buffer_move_state_p1 != 0x2 && buffer_move_state_p1 != 0x3) {
                                //std::cout << "stun_buffer = " << buffer_move_state_p1 << std::endl;

                                Press_any_key('o', 17);
                                ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p1, &buffer_move_state_p1, sizeof(buffer_move_state_p1), nullptr);
                                if (buffer_move_state_p1 != 0x2) {

                                    Sleep(250);
                                    Press_any_key('p', 17);
                                    Sleep(250);
                                    Press_any_key('i', 17);
                                    Sleep(100);

                                }


                            }

                        


                    }

                    if (GetAsyncKeyState(0x5A)) {     //   0x46	F key  0x5A	Z key


                        if (side == true) {
                            Press_any_three_key('d', 'k', 'o', 17);
                        }

                        if (side == false) {

                            Press_any_three_key('a', 'k', 'o', 17);
                        }

                     
                        Sleep(150);  // 260 summary
                        ReadProcessMemory(hProcess, (LPCVOID*)attackaddress_P1, &p1Value, sizeof(p1Value), nullptr);
                        if (p1Value != high && p1Value != mid && p1Value != low)
                        {
                            Sleep(109);  //  260 - 150   = 110 

                            if (side == true) {
                                Press_any_key('d', 17);
                            }

                            if (side == false) {

                                Press_any_key('a', 17);
                            }



                            
                            Sleep(280);
                            ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p1, &buffer_move_state_p1, sizeof(buffer_move_state_p1), nullptr);
                            ReadProcessMemory(hProcess, (LPCVOID*)second_true_address_distance, &inp_buff2, sizeof(inp_buff2), nullptr);

                            // 280 
                            if (inp_buff2 <= dd && buffer_move_state_p1 != 0x5 && buffer_move_state_p1 != 0x6 && buffer_move_state_p1 != 0x7)
                            {
                                Press_any_two_key('i', 'p', 17);


                            }

                            if (inp_buff2 <= dd && (buffer_move_state_p1 == 0x5 || buffer_move_state_p1 == 0x6 || buffer_move_state_p1 == 0x7))
                            {
                                Press_any_key('i', 17);


                            }



                        }

                        if (p1Value == high || p1Value == mid || p1Value == low)
                        {

                            Press_any_key('a', 17);


                        }

                    }
                    /********************************/


                    



                    ////////////////*
                    if (block == true) {

                        if (ammoValue == high && inp_buff2 < dd && (buff_input_address_1 == 0xA00 || buff_input_address_1 == 0x1400)) {

                            jeb_zahvat();

                        }
                        


                    }


                    if (punish == true) {
                       
                        ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p2, &buffer_move_state_p2, sizeof(buffer_move_state_p2), nullptr);

                        if (buffer_move_state_p2 == 0x3)
                        {

                            if (p1Value == high && inp_buff2 < d18)
                            {

                                if (p1Value == high && inp_buff2 < d18 && (buff_input_address_1 == 0x200 || buff_input_address_1 == 0x400)) {

                                    jeb_fast();

                                }



                            }

                        }

                       
                    }

                    if (step_on == true) {

                        if (inp_buff2 <= d26)
                        {
                            ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p2, &buffer_move_state_p2, sizeof(buffer_move_state_p2), nullptr);

                            //jin
                            if (buffer_move_state_p2 == 0x3)
                            {       //jin start
                                if (move_id_buffer_p1 == 1552)
                                {
                                    side_step_w();
                                }

                                if (move_id_buffer_p1 == 1606)
                                {
                                    side_step_s();
                                }
                                //jin end

                                 //noctis start

                               /* if (move_id_buffer_p1 == 1474)
                                {
                                    side_step_bdc();
                                    Sleep(17);
                                    side_step_bdc();
                                }*/

                               /* if (move_id_buffer_p1 == 1489)
                                {
                                    side_step_s();
                                }*/

                                if (move_id_buffer_p1 == 1535)
                                {
                                    if (inp_buff2 <= dd)
                                    {
                                        side_step_w();
                                    }
                                }



                                if (move_id_buffer_p1 == 1636 || move_id_buffer_p1 == 1637)
                                {
                                    if (inp_buff2 <= dd)
                                    {

                                        side_step_w();
                                    }
                                }


                              
                                //noctis end


                            }

                        }

                        if (buffer_move_state_p1 == 0x1)
                        {

                            if (inp_buff2 <= dd)
                            {

                                ReadProcessMemory(hProcess, (LPCVOID)adress_move_state_p2, &buffer_move_state_p2, sizeof(buffer_move_state_p2), nullptr);
                                //noctis start

                               /*if (move_id_buffer_p2 == 1474)
                               {
                                   Press_any_key('w', 17);
                                   Sleep(166);
                                   Press_any_key('s', 17);
                                   Sleep(166);
                                   Press_any_key('s', 166);
                               }

                               if (move_id_buffer_p2 == 1489)
                               {
                                   side_step_s();
                               }*/
                               /* if (move_id_buffer_p1 == 1476)
                                {
                                    Sleep(85);
                                    jeb_fast();
                                    std::cout << "move_id_buffer_p2 = " << move_id_buffer_p2 << std::endl;
                                }

                                if (move_id_buffer_p1 == 1477)
                                {
                                    Sleep(85);
                                    Press_any_key('w', 17);
                                    std::cout << "move_id_buffer_p2 = " << move_id_buffer_p2 << std::endl;
                                    Sleep(177);
                                }*/


                                if (move_id_buffer_p1 == 1618)
                                {
                                    jeb_fast();

                                }

                                if (move_id_buffer_p1 == 1630)
                                {
                                    jeb_fast();

                                }


                                //noctis end

                            }

                        }


                    }

                    // low now
                    if (low_on == true) {
                        if (p1Value == low && inp_buff2 < dd) {
                            if (lwhit == true) {
                                if (side == true) {
                                    for (int i = 0; i <= 16; i++) {
                                        Press_any_two_key('s', 'd', 16);
                                    }
                                }
                                ////////////////////////////////
                                if (side == false) {
                                    for (int i = 0; i <= 16; i++) {
                                        Press_any_two_key('s', 'a', 16);
                                    }
                                }
                            }
                            if (lwhit == false) {
                                // Press_any_key('s', 200);
                                if (side == true) {
                                    noga();
                                }
                            
                            ////////////////////////////////
                            if (side == false) {
                                noga2();
                            }
                        }
                            

                        }
                    }

                    // low  end

                    if (throw_on == true) {
                        if (throw_value_p2 == throw_1 || throw_4 || throw_5) {

                            if (throw_value_p2 == throw_1) {

                                // throw 1
                                Press_i_key();


                            }

                            if (throw_value_p2 == throw_4) {

                                // throw 4
                                Press_two_key();

                            }

                            if (throw_value_p2 == throw_5) {

                                // throw 5
                                Press_p_key();

                            }


                        }
                    }


                }
                

            }
        }
        CloseHandle(hProcess);


    }





    BOOL APIENTRY DllMain(HMODULE hModule,
        DWORD  ul_reason_for_call,
        LPVOID lpReserved
    )
    {
        switch (ul_reason_for_call)
        {
        case DLL_PROCESS_ATTACH: {
            DisableThreadLibraryCalls(hModule);
            CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)laine, NULL, NULL, NULL);
        }
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
        }
        return TRUE;
    }