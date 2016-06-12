kmain()
{
       char* vidmem=(char*)0xb8000;
       
       vidmem[0] = 'X';
       vidmem[1] = 0x02;
}
