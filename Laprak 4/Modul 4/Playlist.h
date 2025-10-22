#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>

struct Lagu {
    std::string judul;
    std::string penyanyi;
    float durasi;
    Lagu* next;
};

class Playlist {
private:
    Lagu* head;

public:
    Playlist();
    ~Playlist();

    void tambahDepan(const std::string& judul, const std::string& penyanyi, float durasi);
    void tambahBelakang(const std::string& judul, const std::string& penyanyi, float durasi);
    void tambahSetelahKe3(const std::string& judul, const std::string& penyanyi, float durasi);
    void hapusBerdasarkanJudul(const std::string& judul);
    void tampilkanPlaylist() const;
};

#endif // PLAYLIST_H
