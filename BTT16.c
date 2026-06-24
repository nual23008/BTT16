#include <stdio.h>
#include <string.h>

#define VO_CUC 999999
#define SO_THANH_PHO 11

char ten_thanh_pho[SO_THANH_PHO][20] = {
    "Ha Noi", 
    "Son Tay", 
    "Thai Nguyen", 
    "Bac Ninh", 
    "Bac Giang",
    "Uong Bi", 
    "Hai Phong", 
    "Hai Duong", 
    "Hung Yen", 
    "Phu Ly", 
    "Hoa Binh"
};

typedef struct {
    int so_luong_dinh;
    int ma_tran_ke[SO_THANH_PHO][SO_THANH_PHO];
} DoThi;

void khoi_tao_do_thi(DoThi *do_thi) {
    int i, j;
    do_thi->so_luong_dinh = SO_THANH_PHO;
    for (i = 0; i < do_thi->so_luong_dinh; i++) {
        for (j = 0; j < do_thi->so_luong_dinh; j++) {
            if (i == j) {
                do_thi->ma_tran_ke[i][j] = 0;
            } else {
                do_thi->ma_tran_ke[i][j] = VO_CUC;
            }
        }
    }
}

void them_canh_noi(DoThi *do_thi, int u, int v) {
    do_thi->ma_tran_ke[u][v] = 1;
    do_thi->ma_tran_ke[v][u] = 1;
}

void tim_duong_ngan_nhat(DoThi *do_thi, int diem_xuat_phat, int diem_dich) {
    int khoang_cach[SO_THANH_PHO];
    int da_duyet[SO_THANH_PHO];
    int vet_duong_di[SO_THANH_PHO];
    int i, buoc;

    for (i = 0; i < do_thi->so_luong_dinh; i++) {
        khoang_cach[i] = VO_CUC;
        da_duyet[i] = 0;
        vet_duong_di[i] = -1;
    }

    khoang_cach[diem_xuat_phat] = 0;

    for (buoc = 0; buoc < do_thi->so_luong_dinh - 1; buoc++) {
        int khoang_cach_nho_nhat = VO_CUC;
        int diem_hien_tai = -1;

        for (i = 0; i < do_thi->so_luong_dinh; i++) {
            if (!da_duyet[i] && khoang_cach[i] < khoang_cach_nho_nhat) {
                khoang_cach_nho_nhat = khoang_cach[i];
                diem_hien_tai = i;
            }
        }

        if (diem_hien_tai == -1) break;

        da_duyet[diem_hien_tai] = 1;

        for (i = 0; i < do_thi->so_luong_dinh; i++) {
            if (!da_duyet[i] && do_thi->ma_tran_ke[diem_hien_tai][i] != VO_CUC && khoang_cach[diem_hien_tai] != VO_CUC) {
                if (khoang_cach[diem_hien_tai] + do_thi->ma_tran_ke[diem_hien_tai][i] < khoang_cach[i]) {
                    khoang_cach[i] = khoang_cach[diem_hien_tai] + do_thi->ma_tran_ke[diem_hien_tai][i];
                    vet_duong_di[i] = diem_hien_tai;
                }
            }
        }
    }

    if (khoang_cach[diem_dich] == VO_CUC) {
        printf("Khong tim thay duong di tu %s den %s\n\n", ten_thanh_pho[diem_xuat_phat], ten_thanh_pho[diem_dich]);
        return;
    }

    int duong_di[SO_THANH_PHO];
    int so_luong_diem = 0;
    int tam_thoi = diem_dich;

    while (tam_thoi != -1) {
        duong_di[so_luong_diem++] = tam_thoi;
        tam_thoi = vet_duong_di[tam_thoi];
    }

    printf("Tuyen duong tu %s den %s:\n", ten_thanh_pho[diem_xuat_phat], ten_thanh_pho[diem_dich]);
    for (i = so_luong_diem - 1; i >= 0; i--) {
        printf("%s", ten_thanh_pho[duong_di[i]]);
        if (i > 0) printf(" -> ");
    }
    printf("\nTong so chang phai di: %d\n\n", khoang_cach[diem_dich]);
}

