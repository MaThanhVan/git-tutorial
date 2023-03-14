#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
    MAY_BAY_THUONG_MAI,
    MAY_BAY_TRUC_THANG,
    XE_KHACH,
    XE_MAY,
    XE_DAP,
    TAU_THUY,
    CA_NO
}phuong_tien;

typedef union 
{
    phuong_tien may_bay_thuong_mai;
    phuong_tien may_bay_truc_thang;
}hang_khong;

typedef union 
{
    phuong_tien xe_khach;
    phuong_tien xe_may;
    phuong_tien xe_dap;
}bo;

typedef union 
{
    phuong_tien tau_thuy;
    phuong_tien ca_no;/* data */
}thuy;

typedef union 
{
    hang_khong duong_hang_khong;/* data */
    bo duong_bo;
    thuy duong_hang_thuy;
    phuong_tien loai_phong_tien;
}phuong_tien_giao_thong;

void duong_hang_khong(phuong_tien_giao_thong *phuong_tien)
{
    new:
    printf("##########################\n");
    printf("-----ban da chon phuong tien hang khong-----\n");
    printf("_____Vui long chon phuong tien_____\n");
    printf("Nhan 1: May bay thuong mai\n");
    printf("Nhan 2: May bay truc thang\n");
    printf("Nhan 0: Quay lai\n");

    int  phim;
    scanf("%d", &phim);
    switch (phim)
    {
    case 0:
       
        chuong_trinh_chon_duong(&phuong_tien);
        exit(0);
    case 1:
        printf("Ban chon: May bay thuong mai\n");           /* code */
        phuong_tien->duong_hang_khong.may_bay_thuong_mai = MAY_BAY_THUONG_MAI;
        break;

    case 2:
        printf("Ban chon: May bay truc thang\n");           /* code */
        phuong_tien->duong_hang_khong.may_bay_truc_thang = MAY_BAY_TRUC_THANG;
        break;

    default:
        printf("Ban nhap sai, hay nhap lai\n");
        goto new;
        break;
    }
}

void duong_bo(phuong_tien_giao_thong *phuong_tien)
{   
    neu:
    printf("##########################\n");
    printf("-----ban da chon phuong tien duong bo-----\n");
    printf("_____Vui long chon phuong tien_____\n");
    printf("Nhan 1: Xe khach\n");
    printf("Nhan 2: Xe may\n");
    printf("Nhan 3: Xe dap\n");
    printf("Nhan 0: Quay lai\n");

    int  phim;
    scanf("%d", &phim);
    switch (phim)
    {
    case 0:
        chuong_trinh_chon_duong(&phuong_tien);
        exit(0);

    case 1:
        printf("Ban chon: xe khach\n");           /* code */
        phuong_tien->duong_bo.xe_khach = XE_KHACH;
        break;

    case 2:
        printf("Ban chon: Xe may\n");           /* code */
        phuong_tien->duong_bo.xe_may = XE_MAY;
        break;

     case 3:
        printf("Ban chon: Xe dap\n");           /* code */
        phuong_tien->duong_bo.xe_dap = XE_DAP;
        break;

    default:
        printf("Ban nhap sai, hay nhap lai");
        goto neu;
        break;
    }
}

void duong_thuy(phuong_tien_giao_thong *phuong_tien)
{
    n:
    printf("##########################\n");
    printf("-----ban da chon phuong tien duong thuy-----\n");
    printf("_____Vui long chon phuong tien_____\n");
    printf("Nhan 1: tau thuy\n");
    printf("Nhan 2: ca no\n");
    printf("Nhan 0: Quay lai\n");

    int  phim;
    scanf("%d", &phim);
    switch (phim)
    {
    case 0:
        chuong_trinh_chon_duong(&phuong_tien);
        exit(0);
    case 1:
        printf("Ban chon: Tau thuy\n");           /* code */
        phuong_tien->duong_hang_thuy.tau_thuy = TAU_THUY;
        break;

    case 2:
        printf("Ban chon: Ca no\n");           /* code */
        phuong_tien->duong_hang_thuy.ca_no = CA_NO;
        break;

    default:
        printf("Ban nhap sai, hay nhap lai");
        goto n;
        break;
    }
}

void hien_thi_gia(phuong_tien_giao_thong phuong_tien)
{
    switch (phuong_tien.loai_phong_tien)
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

void chuong_trinh_chon_duong(phuong_tien_giao_thong *phuong_tien)
{
    menu:
    printf("Ban muon di duong nao:\n");
    printf("Nhan 1: Duong hang khong\n");
    printf("Nhan 2: Duong bo\n");
    printf("Nhan 3: Duong thuy\n");
    printf("Nhan 0: thoat chuong trinh\n");

    int phim = 0;
    scanf("%d", &phim);
    phuong_tien_giao_thong loai_phuong_tien;
    switch (phim)
    {
    case 1: /* constant-expression */
        duong_hang_khong(phuong_tien);
        hien_thi_gia(*phuong_tien);    /* code */
        goto menu;
        break;

    case 2: /* constant-expression */
        duong_bo(phuong_tien);
        hien_thi_gia(*phuong_tien);    /* code */
        goto menu;
        break;

    case 3: /* constant-expression */
        duong_thuy(phuong_tien);
        hien_thi_gia(*phuong_tien);    /* code */
        goto menu;
        break; 
        
    case 0:
        exit(0);

    default:
        printf("Ban nhap sai, hay nhap lai");
        goto menu;
        break;
    }
}





int main(int argc, char const *argv[])
{
    phuong_tien_giao_thong phuong_tien;

    chuong_trinh_chon_duong(&phuong_tien);

    

    return 0;
}


