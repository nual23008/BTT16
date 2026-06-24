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

