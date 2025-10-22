#include "Playlist.h"

Playlist::Playlist() : head(nullptr) {}

Playlist::~Playlist() {
    Lagu* cur = head;
    while (cur != nullptr) {
        Lagu* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

void Playlist::tambahDepan(const std::string& judul, const std::string& penyanyi, float durasi) {
    Lagu* baru = new Lagu{judul, penyanyi, durasi, head};
    head = baru;
    std::cout << "Lagu \"" << judul << "\" ditambahkan di awal.\n";
}


void Playlist::tambahBelakang(const std::string& judul, const std::string& penyanyi, float durasi) {
    Lagu* baru = new Lagu{judul, penyanyi, durasi, nullptr};
    if (head == nullptr) {
        head = baru;
    } else {
        Lagu* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = baru;
    }
    std::cout << "Lagu \"" << judul << "\" ditambahkan di akhir.\n";
}


void Playlist::tambahSetelahKe3(const std::string& judul, const std::string& penyanyi, float durasi) {
    if (head == nullptr) {
        
        tambahBelakang(judul, penyanyi, durasi);
        return;
    }

    Lagu* temp = head;
    int count = 1;
    while (temp != nullptr && count < 3) {
        temp = temp->next;
        ++count;
    }

    if (temp == nullptr) {
        
        std::cout << "Playlist kurang dari 3 lagu. Menambahkan di akhir.\n";
        tambahBelakang(judul, penyanyi, durasi);
        return;
    }

    Lagu* baru = new Lagu{judul, penyanyi, durasi, temp->next};
    temp->next = baru;
    std::cout << "Lagu \"" << judul << "\" ditambahkan setelah lagu ke-3.\n";
}

void Playlist::hapusBerdasarkanJudul(const std::string& judul) {
    if (head == nullptr) {
        std::cout << "Playlist kosong. Tidak ada yang dihapus.\n";
        return;
    }

    Lagu* cur = head;
    Lagu* prev = nullptr;
    while (cur != nullptr && cur->judul != judul) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == nullptr) {
        std::cout << "Tidak ditemukan lagu dengan judul \"" << judul << "\".\n";
        return;
    }

    if (prev == nullptr) {
        // hapus head
        head = cur->next;
    } else {
        prev->next = cur->next;
    }
    delete cur;
    std::cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
}

void Playlist::tampilkanPlaylist() const {
    if (head == nullptr) {
        std::cout << "Playlist kosong.\n";
        return;
    }
    const Lagu* temp = head;
    int idx = 1;
    std::cout << "=== Playlist ===\n";
    while (temp != nullptr) {
        std::cout << idx++ << ". Judul: " << temp->judul
                  << " | Penyanyi: " << temp->penyanyi
                  << " | Durasi: " << temp->durasi << " menit\n";
        temp = temp->next;
    }
    std::cout << "===============\n";
}
