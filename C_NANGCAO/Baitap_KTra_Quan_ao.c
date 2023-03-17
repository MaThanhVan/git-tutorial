#include <stdio.h>
#include <stdint.h>


uint8_t gio_hang;      // 1 byte 0bxxxxxxx
#define Kiem_tra_san_pham(do_dung)                                              \
    if(((*gio_hang & do_dung) == do_dung) & ((temp & do_dung) == do_dung))      \
    {                                                                           \
        printf("%s ----- da ton tai trong gio hang\n", #do_dung);               \
    }                                                                           \
    else if((temp & do_dung) == do_dung)                                        \
        printf("%s ------ khong ton tai trong gio hang\n", #do_dung)            \

#define KIEM_TRA_GIO_HANG(DO_DUNG)                                              \                      
    if ((*gio_hang & DO_DUNG) == DO_DUNG)                                       \
        {i++; printf("%d %s \n", i, #DO_DUNG);}
                                        
typedef enum{
    AO       = 1<<0,        //0b00000001        dich bit
    QUAN     = 1<<1,        //0b00000010
    VAY      = 1<<2,        //0b00000100
    DAM      = 1<<3,        //0b00001000
    NHAN     = 1<<4,        //0b00010000
    VONG_TAY = 1<<5,        //0b00100000
    GIAY     = 1<<6,        //0b01000000
    TUI      = 1<<7         //0b10000000
}DO_DUNG_CA_NHAN;

void Them_vao_gio_hang(uint8_t *gio_hang, DO_DUNG_CA_NHAN loai_do_dung)
{
    *gio_hang |= loai_do_dung;
}
void Xoa_khoi_gio_hang(uint8_t *gio_hang, DO_DUNG_CA_NHAN loai_do_dung)
{
    *gio_hang &= ~loai_do_dung;
}

void Kiem_tra_hang(uint8_t *gio_hang, DO_DUNG_CA_NHAN do_dung)
{
    DO_DUNG_CA_NHAN temp = do_dung;
    Kiem_tra_san_pham(AO);
    Kiem_tra_san_pham(QUAN);
    Kiem_tra_san_pham(VAY);
    Kiem_tra_san_pham(DAM);
    Kiem_tra_san_pham(NHAN);
    Kiem_tra_san_pham(VONG_TAY);
    Kiem_tra_san_pham(GIAY);
    Kiem_tra_san_pham(TUI);
}

void Hien_thi_gio_hang(uint8_t *gio_hang)
{
    int i=0;
    printf("STT TEN <gio hang gom co>\n");
    KIEM_TRA_GIO_HANG(AO);
    KIEM_TRA_GIO_HANG(QUAN);
    KIEM_TRA_GIO_HANG(VAY);
    KIEM_TRA_GIO_HANG(DAM)
    KIEM_TRA_GIO_HANG(NHAN);
    KIEM_TRA_GIO_HANG(VONG_TAY);
    KIEM_TRA_GIO_HANG(GIAY);
    KIEM_TRA_GIO_HANG(TUI);
}

int main(int argc, char const *argv[])
{
    Them_vao_gio_hang(&gio_hang, NHAN|AO|GIAY|QUAN);
    Hien_thi_gio_hang(&gio_hang);
    Kiem_tra_hang(&gio_hang, NHAN|AO|GIAY|QUAN|VAY|DAM|VONG_TAY|TUI);
}