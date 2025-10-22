#include <iostream>
#include <string>
#include <limits>
#include "Playlist.h"
#include "Playlist.cpp"

int main() {
    Playlist myPlaylist;
    int pilihan = -1;

    while (true) {
        std::cout << "\n=== MENU PLAYLIST ===\n";
        std::cout << "1. Tambah lagu di awal\n";
        std::cout << "2. Tambah lagu di akhir\n";
        std::cout << "3. Tambah lagu setelah lagu ke-3\n";
        std::cout << "4. Hapus lagu berdasarkan judul\n";
        std::cout << "5. Tampilkan playlist\n";
        std::cout << "0. Keluar\n";
        std::cout << "Pilih: ";
        if (!(std::cin >> pilihan)) {
            // jika input bukan angka
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input tidak valid. Masukkan angka.\n";
            continue;
        }

        // buang newline yang tersisa sebelum getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (pilihan == 0) {
            std::cout << "Keluar dari program.\n";
            break;
        }

        std::string judul, penyanyi;
        float durasi = 0.0f;

        switch (pilihan) {
            case 1:
                std::cout << "Masukkan judul lagu: ";
                std::getline(std::cin, judul);
                std::cout << "Masukkan penyanyi: ";
                std::getline(std::cin, penyanyi);
                std::cout << "Masukkan durasi (menit, contoh 3.5): ";
                if (!(std::cin >> durasi)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Durasi tidak valid. Batalkan operasi.\n";
                } else {
                    myPlaylist.tambahDepan(judul, penyanyi, durasi);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break;

            case 2:
                std::cout << "Masukkan judul lagu: ";
                std::getline(std::cin, judul);
                std::cout << "Masukkan penyanyi: ";
                std::getline(std::cin, penyanyi);
                std::cout << "Masukkan durasi (menit): ";
                if (!(std::cin >> durasi)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Durasi tidak valid. Batalkan operasi.\n";
                } else {
                    myPlaylist.tambahBelakang(judul, penyanyi, durasi);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break;

            case 3:
                std::cout << "Masukkan judul lagu: ";
                std::getline(std::cin, judul);
                std::cout << "Masukkan penyanyi: ";
                std::getline(std::cin, penyanyi);
                std::cout << "Masukkan durasi (menit): ";
                if (!(std::cin >> durasi)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Durasi tidak valid. Batalkan operasi.\n";
                } else {
                    myPlaylist.tambahSetelahKe3(judul, penyanyi, durasi);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break;

            case 4:
                std::cout << "Masukkan judul lagu yang ingin dihapus: ";
                std::getline(std::cin, judul);
                myPlaylist.hapusBerdasarkanJudul(judul);
                break;

            case 5:
                myPlaylist.tampilkanPlaylist();
                break;

            default:
                std::cout << "Pilihan tidak valid.\n";
                break;
        } // switch
    } // while

    return 0;
}
