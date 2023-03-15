#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


typedef enum{
    MAY_BAY_THUONG_MAI,
    MAY_BAY_TRUC_THANG,
    XE_KHACH,
    XE_MAY,
    XE_DAP,
    TAU_THUY,
    CA_NO,
}phuong_tien;


typedef union{
    phuong_tien may_bay_thuong_mai;
    phuong_tien may_bay_truc_thang;
}hang_khong;

typedef union{
    phuong_tien xe_khach;
    phuong_tien xe_may;
    phuong_tien xe_dap;
}bo;

typedef union{
    phuong_tien tau_thuy;
    phuong_tien ca_no;
}thuy;

typedef union{
    hang_khong duong_hang_khong;
    bo duong_bo;
    thuy duong_thuy;
    phuong_tien loai_phuong_tien;
}phuong_tien_giao_thong;

///////////////////////Chuong chinh chon phuong tien

#define LOAI_HINH_GIAO_THONG(ten_duong, ...)                        \
    void ten_duong(phuong_tien_giao_thong *phuong_tien){            \
    printf("--------Ban da chon %s---------\n", #ten_duong);        \
    printf("Vui long chon loai phuong tien\n");                     \
    int phim = 0;                                                   \
    do{                                                             \
    __VA_ARGS__                                                     \
    scanf("%d", &phim);       }                                     \
    while (1);                                                      \
    }



#define KEY(key)  key

#define NAME(name) name

#define VALUE(value) value

#define DISPLAY(key, name)                                      \
    printf("Nhan %d: %s\n", key, name);

#define IF(key, name, value)                                    \
if(phim == key){                                                \
    printf("--------Ban chon: %s---------- \n", name);          \
    value;                                                      \
    break;                                                      \
}



#define KEY_VALUE(key, name, value)                             \
DISPLAY(key, name)                                              \
IF(key, name, value)

LOAI_HINH_GIAO_THONG(
        duong_hang_khong,
        KEY_VALUE(
            KEY(1),
            NAME("May bay thuong mai"),
            VALUE(phuong_tien->duong_hang_khong.may_bay_thuong_mai = MAY_BAY_THUONG_MAI)
        )
        KEY_VALUE(
            KEY(2),
            NAME("May bay truc thang"),
            VALUE(phuong_tien->duong_hang_khong.may_bay_truc_thang = MAY_BAY_TRUC_THANG)
        ))

LOAI_HINH_GIAO_THONG(
        duong_bo,
        KEY_VALUE(
            KEY(1),
            NAME("Xe khach"),
            VALUE(phuong_tien->duong_bo.xe_khach = XE_KHACH)
        )
        KEY_VALUE(
            KEY(2),
            NAME("Xe may"),
            VALUE(phuong_tien->duong_bo.xe_may = XE_MAY)
        )
        KEY_VALUE(
            KEY(3),
            NAME("Xe dap"),
            VALUE(phuong_tien->duong_bo.xe_dap = XE_DAP)
        ))

LOAI_HINH_GIAO_THONG(
        duong_thuy,
        KEY_VALUE(
            KEY(1),
            NAME("Tau thuy"),
            VALUE(phuong_tien->duong_thuy.tau_thuy = TAU_THUY)
        )
        KEY_VALUE(
            KEY(2),
            NAME("Ca No"),
            VALUE(phuong_tien->duong_thuy.ca_no = CA_NO)
        ))

// //////////////////////////////////////////////////////////////// chọn chương trình

void Chuong_Trinh_Chon_Duong(phuong_tien_giao_thong *phuong_tien){
    printf("Ban muon di chuyen bang duong nao?\n");
    printf("Nhan 1: Duong Hang Khong\n");
    printf("Nhan 2: Duong Bo\n");
    printf("Nhan 3: Duong Thuy\n");
    printf("Nhan 0: Thoat chuong trinh\n");


    int phim = 0;
    scanf("%d", &phim);

    switch (phim)
    {
        case 0:
        exit(0);
    case 1:
        duong_hang_khong(phuong_tien);
        break;
    case 2:
        duong_bo(phuong_tien);
        break;
    case 3:
        duong_thuy(phuong_tien);
        break;
    default:
        printf("Nhap phim khong hop le:");
        Chuong_Trinh_Chon_Duong(&phuong_tien);
        break;
    }
}



/////////////////////////////////////////////////////////// chương trình in giá tiền 

 
void hien_thi_gia(phuong_tien_giao_thong phuong_tien)
{
    switch (phuong_tien.loai_phuong_tien)
    {
    case MAY_BAY_THUONG_MAI:
        printf("loai phuong tien: May bay thuong mai \n" );
        printf("Gia ve: 1.200.000 vnd\n\n");
        break;
    
    case MAY_BAY_TRUC_THANG:
        printf("loai phuong tien: May bay truc thang \n" );
        printf("Gia ve: 10.000.000 vnd\n");
        break;

    case XE_KHACH:
        printf("loai phuong tien: xe khach \n" );
        printf("Gia ve: 200.000 vnd\n");
        break;
    case XE_MAY:
        printf("loai phuong tien: xe may \n" );
        printf("Gia ve: 100.000 vnd\n");
        break;

    case XE_DAP:
        printf("loai phuong tien: xe dap \n" );
        printf("Gia ve: 10.000 vnd\n");
        break;

    case TAU_THUY:
        printf("loai phuong tien: tau thuy \n" );
        printf("Gia ve: 2.000.000 vnd\n");
        break;
    
    case CA_NO:
        printf("loai phuong tien: ca no \n" );
        printf("Gia ve: 20.000.000 vnd\n");
        break;

    default:
        break;
    }
    
}
int main(int argc, char const *argv[])
{
    

    phuong_tien_giao_thong phuong_tien;
    Chuong_Trinh_Chon_Duong(&phuong_tien);
    hien_thi_gia(phuong_tien);

   
    

    return 0;
}
