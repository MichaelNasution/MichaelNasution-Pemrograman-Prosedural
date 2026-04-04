// 12S24003 - Michael Pratama Nasution
// 12S24019 - Winda N. V. Sitorus

#include <stdio.h>
int main() {
  int x1;
  int x2;
  scanf("%d %d", &x1, &x2);
  int waktu_tiap_transaksi = 3;
  int max_tiap_transaksi = 3;
  int antrean_ucok = (x1 + waktu_tiap_transaksi - 1) / max_tiap_transaksi;
  int antrean_butet = (x2 + max_tiap_transaksi -1) / max_tiap_transaksi;
  int waktu_tunggu_ucok = 0, waktu_tunggu_butet = 0, total = 0;
  
  while (antrean_ucok > 0 || antrean_butet > 0) {
    if (antrean_ucok > 0) {
        total += waktu_tiap_transaksi;
        waktu_tunggu_ucok = total;
        antrean_ucok--;
    }
    if (antrean_butet > 0) {
        total += waktu_tiap_transaksi;
        waktu_tunggu_butet = total;
        antrean_butet--;
    }
}
printf("%d\n%d\n%d\n", waktu_tunggu_ucok, waktu_tunggu_butet, waktu_tunggu_ucok+waktu_tunggu_butet);
return 0;
}