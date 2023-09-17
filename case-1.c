#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <time.h>

// Struktur untuk menyimpan waktu dan countdown
struct Countdown
{
    time_t start_time;     // Waktu saat inisialisasi
    int countdown_hours;   // Durasi hitungan mundur dalam jam
    int countdown_minutes; // Durasi hitungan mundur dalam menit (default 0)
    int countdown_seconds; // Durasi hitungan mundur dalam detik (default 0)
};
int PRICE_PER_HOUR = 10000;

bool isValidNumber(char input[]);
int getDiscount(int duration);
void menuBookingPlace();
void menuPriceList();
void menuReferenceList();
int playGame(int duration);
void initializeCountdown(struct Countdown *cd, int hours);
int getRemainingTime(struct Countdown cd);
void theGame(int duration);

void clearscr()
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || \
    (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}

int main()
{
    bool run = true;
    bool isActive = true;
    int menu;
    char namaPengguna[100];

    while (run)
    {
        // Bersihkan layar
        clearscr();
        printf("===================================\n");
        printf("PROGRAM BILLING GAME ONLINE\n");
        printf("===================================\n\n\n");
        printf("Masukan Nama Anda:");
        scanf("%s", namaPengguna);
        getchar();
        isActive = true;
        // Selama isActive nya true maka akan tampilkan menu
        while (isActive)
        {

            // Bersihkan layar dari kalimat yang sudah diprint
            clearscr();
            printf("===================================\n");
            printf("T E B A K  A N G K A");

            printf("\n===================================\n");
            printf("Selamat Datang : %s \n", namaPengguna);
            printf("===================================\n");
            printf("Silahkan Memilih Menu Di Bawah");
            printf("\n===================================\n\n");
            printf("Menu:\n");
            printf("1. Play\n");
            printf("2. Daftar Harga\n");
            printf("3. Referensi\n");
            printf("4. Log out\n");
            printf("5. Keluar\n");

            while (1)
            {
                char inputMenu[100];
                printf("Pilih menu (1-5): ");
                scanf("%s", inputMenu);
                getchar();
                // Error Checking. Validasi apakah menu yang diinput merupakan angka yang valid
                if (isValidNumber(inputMenu))
                {
                    // Konversi dari string jadi integer
                    menu = atoi(inputMenu);
                    if (menu >= 1 && menu <= 5)
                    {
                        break;
                    }
                }
                printf("\nMenu yang anda masukkan tidak valid\n");
            }

            // Pengkondisian berdasarkan menu yang dipilih
            switch (menu)
            {
            case 1:
                menuBookingPlace();
                break;
            case 2:
                menuPriceList();
                break;
            case 3:
                menuReferenceList();
                break;
            case 4:
                printf("Terima kasih. Silahkan datang lagi dilain waktu.\n");
                isActive = false;
                break;
            case 5:
                printf("Terima kasih. Silahkan datang lagi dilain waktu.\n");
                isActive = false;
                run = false;
                break;

            default:
                printf("Terima kasih. Silahkan datang lagi dilain waktu.\n");
                isActive = false;
                break;
            }
        }
    }

    return 0;
}

// Fungsi untuk cek apakah yang diinput oleh user merupakan angka yang valid
bool isValidNumber(char input[])
{
    bool isValid = true;
    for (int i = 0; i < strlen(input); i++)
    {
        if (!isdigit(input[i]))
        {
            isValid = false;
            break;
        }
    }
    return isValid;
}
// Fungsi untuk menghitung diskon yang diperoleh berdasarkan durasi bermain game
int getDiscount(int duration)
{
    int discount = 0;

    if (duration > 10)
    {
        discount = 25;
    }
    else if (duration > 8)
    {
        discount = 20;
    }
    else if (duration > 6)
    {
        discount = 15;
    }
    else if (duration > 4)
    {
        discount = 10;
    }

    return discount;
}
// FUngsi untuk memproses pemesanan tempat dan alat untuk bermain game online
void menuBookingPlace()
{
    int duration;
    int discount;

    // Bersihkan layar
    clearscr();
    printf("===================================\n");
    printf("T E B A K  A N G K A");

    printf("\n===================================\n");
    printf("\n\n===================================\n");
    printf("P L A Y");
    printf("\n===================================\n");
    while (1)
    {

        printf("\n\nSilahkan input berapa lama anda ingin bermain ( dalam jam dan minimal 1 jam ): ");
        char inputHours[100];
        scanf("%s", inputHours);
        getchar();
        // Error checking. Validasi apakah yang diinput user adalah angka yang valid
        if (isValidNumber(inputHours))
        {
            duration = atoi(inputHours);
            if (duration >= 1)
            {
                break;
            }
        }
        printf("Input anda tidak valid\n");
    }
    // Perhitungan diskon
    discount = getDiscount(duration);
    float price = duration * PRICE_PER_HOUR;
    if (discount > 0)
    {
        price = (float)price * (100 - discount) / 100;
    }

    // Output
    // Bersihkan layar dari kalimat yang sudah diprint

    printf("\n===================================\n");
    printf("BIAYA UNTUK MEMAINKAN GAME TEBAK ANGKA\n");
    printf("===================================\n\n\n");
    printf("Anda ingin bermain game online untuk %d jam\n", duration);
    printf("Biaya yang harus anda bayar adalah: Rp %.2f\n", (float)duration * PRICE_PER_HOUR);
    printf("Anda mendapatkan diskon %d%%\n", discount);
    printf("Harga akhir yang harus anda bayar adalah Rp %.2f\n", price);
    printf("\nTekan enter untuk lanjut..\n");
    while (getchar() != '\n')
    {
    }
    while (1)
    {
        char bayar[100];
        printf("Apakah anda ingin membayar? Rp %.2f (y/n): ", price);
        scanf("%s", bayar);
        getchar();
        // Error Checking. Validasi apakah yang diinput merupakan valid
        if (bayar[0] == 'y')
        {
            // Tindakan jika pengguna memilih 'y'
            clearscr();
            printf("===================================\n");
            printf("T E B A K  A N G K A");

            printf("\n===================================\n");
            printf("\n===================================\n");
            printf("Pembayaran Sukses Sebesar: Rp %.2f\n", price);
            printf("\n===================================\n");
            printf(" R I N C I A N\n");
            printf("\nHARGA BERMAIN SELAMA  %d jam:", duration);
            printf("\n----- Rp %.2f\n", (float)duration * PRICE_PER_HOUR);
            printf("\n\nDISCOUNT YANG ANDA DAPATKAN:");
            printf("\n----- %d%%\n", discount);
            printf("\n\nHARGA AKHIR YANG ANDA BAYARKAN:");
            printf("\n----- Rp %.2f\n", price);
            printf("\n===================================\n");

            printf("\nTekan enter untuk lanjut..\n");
            while (getchar() != '\n')
            {
            }
            theGame(duration);

            break;
        }
        else if (bayar[0] == 'n')
        {
            // Tindakan jika pengguna memilih 'n'
            // Bersihkan layar dari kalimat yang sudah diprint
            clearscr();

            printf("===================================\n");
            printf("T E B A K  A N G K A");

            printf("\n===================================\n");
            printf("\n===================================\n");
            printf("Anda tidak membayar.");
            printf("\n===================================\n");
            printf("\nTekan enter untuk kembali ke menu awal..\n");
            while (getchar() != '\n')
            {
            }
            break;
        }
        else
        {
            // Tindakan jika input tidak valid
            printf("\nPilihan tidak valid. Silahkan masukkan 'y' atau 'n'.\n");
        }
    }
}
// Fungsi untuk menampilkan daftar harga dan diskon
void menuPriceList()
{
    printf("a. Harga per jam adalah Rp 10.000\n");
    printf("b. Akan mendapatkan diskon sebesar 10%% jika bermain lebih dari 4 jam\n");
    printf("c. Akan mendapatkan diskon sebesar 15%% jika bermain lebih dari 6 jam\n");
    printf("d. Akan mendapatkan diskon sebesar 20%% jika bermain lebih dari 8 jam\n");
    printf("e. Akan mendapatkan diskon sebesar 25%% jika bermain lebih dari 10 jam\n");

    printf("\nSilahkan tekan enter untuk lanjut..\n");
    while (getchar() != '\n')
    {
    }
}
// Fungsi untuk menampilkan daftar referensi yang digunakan untuk mengerjakan tugas ini
void menuReferenceList()
{
    printf("a. Convert String to Int in C (https://www.geeksforgeeks.org/convert-string-to-int-in-c/)\n");
    printf("b. isdigit to Validate If Input Is Number (https://cboard.cprogramming.com/c-programming/149221-isdigit-validate-if-input-number.html)\n");

    printf("\nTekan enter untuk lanjut..\n");
    while (getchar() != '\n')
    {
    }
}

// Fungsi awal untuk menjalankan sebuah game tebak angka
void theGame(int duration)
{
    clearscr();
    printf("===================================\n");
    printf("T E B A K  A N G K A");

    printf("\n===================================\n");
    printf("\n===================================\n");
    printf("Anda Memiliki Waktu Bermain Sebanyak %d jam\n", duration);
    printf("\n===================================\n");
    printf("\nTekan enter untuk mulai bermain....\n");
    while (getchar() != '\n')
    {
    }

    playGame(duration);
}

// fungsi untuk mengecek input adalah bilangan bulat
bool isInteger(const char *input)
{
    // Fungsi untuk memeriksa apakah input adalah bilangan bulat
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return false;
        }
    }
    return true;
}

// fungsi yang menjalankan permainan tebak angka
int playGame(int duration)
{

    struct Countdown countdown;
    initializeCountdown(&countdown, duration);
    int remaining_time = getRemainingTime(countdown);
    int remaining_hours = remaining_time / 3600;
    int remaining_minutes = (remaining_time % 3600) / 60;
    int remaining_seconds = remaining_time % 60;

    const int MIN = 1;
    const int MAX = 10;
    int guess = 0;
    int guesses = 0;
    int answer = 0;
    int score = 0;

    // Menggunakan waktu saat ini sebagai seed untuk generator angka acak
    srand(time(0));

    printf("===================================\n");
    printf("\nT E B A K  A N G K A\n");
    printf("\nScore Awal: %d\n", score);
    printf("\nSisa waktu: %02d:%02d:%02d\n", remaining_hours, remaining_minutes, remaining_seconds);

    printf("\n===================================\n");

    while (remaining_time > 0)
    {
        guess = 0;
        printf("Tebak Angka dari 1 sampai 10 ( input selain angka untuk keluar dari game): ");
        char input[100];
        scanf("%s", input);

        if (isInteger(input))
        {
            guess = atoi(input);
            answer = (rand() % MAX) + MIN;

            if (guess > answer)
            {
                remaining_time = getRemainingTime(countdown);
                remaining_hours = remaining_time / 3600;
                remaining_minutes = (remaining_time % 3600) / 60;
                remaining_seconds = remaining_time % 60;
                guesses++;
                // Bersihkan layar dari kalimat yang sudah diprint
                clearscr();

                printf("===================================\n");
                printf("T E B A K  A N G K A");

                printf("\n===================================\n");

                printf("\n**********************\n");
                printf("\nJAWABAN ANDA SALAH!\n");

                printf("\n**********************\n");
                printf("\nTebakan Anda:%d\n", guess);
                printf("\nTebakan Yang Benar: %d\n", answer);
                printf("\nGame ke: %d\n", guesses);
                printf("\n**********************\n");
                printf("\nScore: %d\n", score);
                printf("\nSisa waktu: %02d:%02d:%02d\n", remaining_hours, remaining_minutes, remaining_seconds);
                printf("\n**********************\n");
            }
            else if (guess < answer)
            {
                remaining_time = getRemainingTime(countdown);
                remaining_hours = remaining_time / 3600;
                remaining_minutes = (remaining_time % 3600) / 60;
                remaining_seconds = remaining_time % 60;
                guesses++;
                // Bersihkan layar dari kalimat yang sudah diprint
                clearscr();

                printf("===================================\n");
                printf("T E B A K  A N G K A");

                printf("\n===================================\n");

                printf("\n**********************\n");
                printf("\nJAWABAN ANDA SALAH!\n");

                printf("\n**********************\n");
                printf("\nTebakan Anda:%d\n", guess);
                printf("\nTebakan Yang Benar: %d\n", answer);
                printf("\nGame ke: %d\n", guesses);
                printf("\n**********************\n");
                printf("\nScore: %d\n", score);
                printf("\nSisa waktu: %02d:%02d:%02d\n", remaining_hours, remaining_minutes, remaining_seconds);
                printf("\n**********************\n");
            }
            else
            {
                remaining_time = getRemainingTime(countdown);
                remaining_hours = remaining_time / 3600;
                remaining_minutes = (remaining_time % 3600) / 60;
                remaining_seconds = remaining_time % 60;
                guesses++;
                // Bersihkan layar dari kalimat yang sudah diprint
                clearscr();

                printf("===================================\n");
                printf("T E B A K  A N G K A");

                printf("\n===================================\n");

                score++;
                printf("\n**********************\n");
                printf("\nSELAMAT JAWABAN ANDA BENAR\n");

                printf("\n**********************\n");
                printf("\nTebakan Anda:%d\n", guess);
                printf("\nTebakan Yang Benar: %d\n", answer);
                printf("\nGame ke: %d\n", guesses);
                printf("\n**********************\n");
                printf("\nScore: %d\n", score);
                printf("\nSisa waktu: %02d:%02d:%02d\n", remaining_hours, remaining_minutes, remaining_seconds);
                printf("\n**********************\n");
            }
        }
        else
        {
            printf("Input bukan merupakan bilangan bulat...\n");
            while (getchar() != '\n')
            {
                // membersihkan karakter karakter tambahan dalam bffer
            }
            char lanjutPermainan[100];
            printf("Apakah anda ingin melanjutkan permainan (y/n): ");
            scanf("%s", lanjutPermainan);
            getchar();
            if (lanjutPermainan[0] == 'y')
            {
                // Melanjutkan Permainan
            }
            else if (lanjutPermainan[0] == 'n')
            {
                // Tindakan jika pengguna memilih 'n'
                // Bersihkan layar dari kalimat yang sudah diprint
                clearscr();
                printf("===================================\n");
                printf("T E B A K  A N G K A");

                printf("\n===================================\n");
                printf("\n===================================\n");
                printf("Anda telah menghentikan Permainan.\n");
                printf("\nWaktu anda hangus....\n");
                printf("\n===================================\n");
                printf("\nTekan enter untuk kembali ke menu awal..\n");
                while (getchar() != '\n')
                {
                }
                break;
            }
            else
            {
                // Tindakan jika input tidak valid
                printf("\nPilihan tidak valid. Silahkan masukkan 'y' atau 'n'.\n");
            }
        }
    }

    return 0;
}

// sekumpulan fungsi untuk menghitung sisa waktu yang ada

// Fungsi untuk menginisialisasi countdown dengan input jam
void initializeCountdown(struct Countdown *cd, int hours)
{
    cd->start_time = time(NULL); // Simpan waktu saat inisialisasi
    cd->countdown_hours = hours;
    cd->countdown_minutes = 0; // Default nilai menit ke 0
    cd->countdown_seconds = 0; // Default nilai detik ke 0
}

// Fungsi untuk mendapatkan sisa waktu hitungan mundur dalam detik
int getRemainingTime(struct Countdown cd)
{
    time_t current_time = time(NULL);                                                                                         // Dapatkan waktu saat ini
    int elapsed_seconds = (int)(current_time - cd.start_time);                                                                // Hitung selisih waktu dalam detik
    int remaining_seconds = (cd.countdown_hours * 3600 + cd.countdown_minutes * 60 + cd.countdown_seconds) - elapsed_seconds; // Hitung sisa waktu

    return (remaining_seconds < 0) ? 0 : remaining_seconds; // Pastikan hasil tidak negatif
}
