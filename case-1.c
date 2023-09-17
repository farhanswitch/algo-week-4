#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int PRICE_PER_HOUR = 10000;

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

bool isValidNumber(char input[]);
int getDiscount(int duration);
void menuBookingPlace();
void menuPriceList();
void menuReferenceList();

int main()
{

    bool isActive = true;
    int menu;

    // Selama isActive nya true maka akan tampilkan menu
    while (isActive)
    {
        // Bersihkan layar dari kalimat yang sudah diprint
        clearscr();
        printf("===================================\n");
        printf("PROGRAM BILLING GAME ONLINE\n");
        printf("===================================\n\n\n");

        printf("Menu:\n");
        printf("1. Pemesanan\n");
        printf("2. Daftar Harga\n");
        printf("3. Referensi\n");
        printf("4. Keluar\n");

        while (1)
        {
            char inputMenu[100];
            printf("Pilih menu (1-4): ");
            scanf("%s", inputMenu);
            getchar();
            // Error Checking. Validasi apakah menu yang diinput merupakan angka yang valid
            if (isValidNumber(inputMenu))
            {
                // Konversi dari string jadi integer
                menu = atoi(inputMenu);
                if (menu >= 1 && menu <= 4)
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
        default:
            printf("Terima kasih. Silahkan datang lagi dilain waktu.\n");
            isActive = false;
            break;
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
    while (1)
    {
        printf("Silahkan input berapa lama anda ingin bermain ( dalam jam dan minimal 1 jam ): ");
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
    printf("Anda ingin bermain game online untuk %d jam\n", duration);
    printf("Biaya yang harus anda bayar adalah: Rp %.2f\n", (float)duration * PRICE_PER_HOUR);
    printf("Anda mendapatkan diskon %d%%\n", discount);
    printf("Harga akhir yang harus anda bayar adalah Rp %.2f\n", price);
    printf("\nTekan enter untuk lanjut..\n");
    while (getchar() != '\n')
    {
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
