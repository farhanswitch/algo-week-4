#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// deklarasi tipe data struct untuk simpan data mahasiswa
struct StudentData
{
    char name[255];
    int nilaiQuis;
    int nilaiTugas;
    int nilaiAbsensi;
    int nilaiPraktek;
    int nilaiUAS;
    float nilaiRataRata;
    char finalGrade;
    char gradeQuis;
    char gradeTugas;
    char gradeAbsensi;
    char gradePraktek;
    char gradeUAS;
    bool isPass;
};

// Deklarasi function prototype
void menuInputData();
void printOutSummary(struct StudentData listStudent[], int count);
void menuReferenceList();
void checkIsExceedTheMinimumGrade(struct StudentData *student);
bool checkIsValidNumber(char input[]);
bool checkIsValidScore(int score);
bool checkIsLettersAndSpacesOnly(char str[255]);
char getGrade(float score);

int main()
{

    bool isActive = true;
    int menu;

    while (isActive)
    {
        system("clear");
        printf("===================================\n");
        printf("PROGRAM INPUT NILAI MAHASISWA\n");
        printf("===================================\n\n\n");

        printf("Menu: \n");
        printf("1. Input Data\n");
        printf("2. Referensi\n");
        printf("3. Keluar\n");

        while (1)
        {
            char inputMenu[100];
            printf("Pilih menu (1-4): ");
            scanf("%s", inputMenu);
            getchar();
            // Error Checking. Validasi apakah menu yang diinput merupakan angka yang valid
            if (checkIsValidNumber(inputMenu))
            {
                // Konversi dari string jadi integer
                menu = atoi(inputMenu);
                if (menu >= 1 && menu <= 3)
                {
                    break;
                }
            }
            printf("\nMenu yang anda masukkan tidak valid\n");
        }

        switch (menu)
        {
        case 1:
            /* code */
            menuInputData();
            break;
        case 2:
            menuReferenceList();
            break;
        case 3:
        default:
            isActive = false;
            break;
        }
    }

    return 0;
}

/**
 * Fungsi untuk cek apakah yang diinput oleh user merupakan angka yang valid
 * {char[]} input - string yang akan dicek
 * returns {bool} akan bernilai true jika valid dan bernilai false jika tidak valid
 */
bool checkIsValidNumber(char input[])
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
/**
 * Function untuk proses input data
 */
void menuInputData()
{
    int count;
    struct StudentData listStudent[1000];

    bool isActive = true;
    while (isActive)
    {
        // Bersihkan layar
        system("clear");
        struct StudentData student;
        printf("Mahasiswa No. %d\n", (count) + 1);
        while (1)
        {
            char name[255];
            printf("Masukkan nama mahasiwa: ");
            scanf("%[^\n]s", name);
            getchar();

            // Error checking. Nama hanya boleh huruf dan spasi
            if (checkIsLettersAndSpacesOnly(name))
            {
                strcpy(student.name, name);
                break;
            }
            printf("Nama hanya boleh terdiri dari huruf dan spasi\n");
        }

        while (1)
        {
            char nilaiQuis[255];
            printf("Masukkan nilai quis: ");
            scanf("%s", nilaiQuis);
            getchar();

            // Nilai harus berupa angka dan ada di range 0-100
            if (checkIsValidNumber(nilaiQuis) && checkIsValidScore(atoi(nilaiQuis)))
            {
                // Convert string to number
                int numQuis = atoi(nilaiQuis);
                student.nilaiQuis = numQuis;
                student.gradeQuis = getGrade(numQuis);
                break;
            }
            printf("Nilai yang anda masukkan tidak valid. Nilai harus berupa angka 0 - 100\n");
        }

        while (1)
        {
            char nilaiTugas[255];
            printf("Masukkan nilai tugas: ");
            scanf("%s", nilaiTugas);
            getchar();
            // Nilai harus berupa angka dan ada di range 0-100
            if (checkIsValidNumber(nilaiTugas) && checkIsValidScore(atoi(nilaiTugas)))
            {
                int numTugas = atoi(nilaiTugas);
                student.nilaiTugas = numTugas;
                student.gradeTugas = getGrade(numTugas);
                break;
            }
            printf("Nilai yang anda masukkan tidak valid. Nilai harus berupa angka 0 - 100\n");
        }

        while (1)
        {
            char nilaiAbsensi[255];
            printf("Masukkan nilai absensi: ");
            scanf("%s", nilaiAbsensi);
            getchar();

            // Nilai harus berupa angka dan ada di range 0-100
            if (checkIsValidNumber(nilaiAbsensi) && checkIsValidScore(atoi(nilaiAbsensi)))
            {
                int numAbsensi = atoi(nilaiAbsensi);
                student.nilaiAbsensi = numAbsensi;
                student.gradeAbsensi = getGrade(numAbsensi);
                break;
            }
            printf("Nilai yang anda masukkan tidak valid. Nilai harus berupa angka 0 - 100\n");
        }
        while (1)
        {
            char nilaiPraktek[255];
            printf("Masukkan nilai praktek: ");
            scanf("%s", nilaiPraktek);
            getchar();

            // Nilai harus berupa angka dan ada di range 0-100
            if (checkIsValidNumber(nilaiPraktek) && checkIsValidScore(atoi(nilaiPraktek)))
            {
                int numPraktek = atoi(nilaiPraktek);
                student.nilaiPraktek = numPraktek;
                student.gradePraktek = getGrade(numPraktek);
                break;
            }
            printf("Nilai yang anda masukkan tidak valid. Nilai harus berupa angka 0 - 100\n");
        }
        while (1)
        {
            char nilaiUAS[255];
            printf("Masukkan nilai UAS: ");
            scanf("%s", nilaiUAS);
            getchar();

            // Nilai harus berupa angka dan ada di range 0-100
            if (checkIsValidNumber(nilaiUAS) && checkIsValidScore(atoi(nilaiUAS)))
            {
                int numUAS = atoi(nilaiUAS);
                student.nilaiUAS = numUAS;
                student.gradeUAS = getGrade(numUAS);
                break;
            }
            printf("Nilai yang anda masukkan tidak valid. Nilai harus berupa angka 0 - 100\n");
        }

        int totalNilai = student.nilaiQuis + student.nilaiTugas + student.nilaiAbsensi + student.nilaiPraktek + student.nilaiUAS;

        student.nilaiRataRata = (float)totalNilai / 5;
        student.finalGrade = getGrade(student.nilaiRataRata);

        // Chech apakah mahasiswa tersebut lulus atau tidak
        checkIsExceedTheMinimumGrade(&student);
        printf("\n\n------------------------------\n");
        printf("Grade nilai quis: %c\n", student.gradeQuis);
        printf("Grade nilai tugas: %c\n", student.gradeTugas);
        printf("Grade nilai absensi: %c\n", student.gradeAbsensi);
        printf("Grade nilai praktek: %c\n", student.gradePraktek);
        printf("Grade nilai UAS: %c\n", student.gradeUAS);

        printf("Nilai rata-rata: %.2f\n", student.nilaiRataRata);
        printf("Grade: %c\n", student.finalGrade);
        printf("Status kelulusan: %s\n", student.isPass ? "Lulus" : "Gagal");
        printf("\n------------------------------\n\n");
        listStudent[count] = student;
        count += 1;

        while (1)
        {
            printf("\nApakah anda ingin menginput data lagi? (y/n): ");
            char input[100];
            scanf("%s", input);
            getchar();
            char firstLetter = input[0];
            // toupper adalah fungsi konversi huruf menjadi kapital
            if (toupper(firstLetter) == 'Y')
            {

                break;
            }
            else if (toupper(firstLetter) == 'N')
            {
                if (count < 10)
                {
                    printf("Saat ini anda sudah menginput %d mahasiswa.\nMinimal jumlah mahasiswa adalah 10.\n", (count) + 1);
                }
                else
                {
                    isActive = false;
                    break;
                }
            }
        }
    }
    printOutSummary(listStudent, count);
}
/**
 * Function untuk cek apakah nilai nya valid atau tidak. Nilai yang valid berada
 * di range 0 - 100
 *
 * {int} score - nilai yang akan dicek
 * returns {bool}
 * */
bool checkIsValidScore(int score)
{
    // Jika nilai berada di rang 0 - 100
    if (score >= 0 && score <= 100)
    {
        return true;
    }
    // Jika nilai tidak diantara 0 - 100
    else
    {
        return false;
    }
}
/**
 * Function untuk cek apakah string hanya terdiri dari huruf dan spasi
 *
 * {string} name - kalimat yang akna dicek
 * returns {int}
 * */
bool checkIsLettersAndSpacesOnly(char nama[255])
{
    // Karakter yang diizinkan
    char lettersAndSpace[100] =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ \0";
    // Dapatkan panjang dari kalimat yg akan dicek
    int inputLength = strlen(nama);
    int totalValid;

    // cek per karakter dari kalimat apakah valid atau tidak
    for (int x = 0; x < inputLength; x++)
    {
        for (int y = 0; y < strlen(lettersAndSpace); y++)
        {
            if (nama[x] == lettersAndSpace[y])
            {
                totalValid++;
                break;
            }
        }
    }

    // Jika jumlah karakter yang valid sama dengan panjang kalimat
    if (inputLength == totalValid)
    {
        return true;
    }
    // Jika jumlah karakter yang valid tidak sama dengan panjang kalimat
    else
    {
        return false;
    }
}
/**
 * Function untuk dapatkan grade berdasarkan nilai
 * {float} score - nilai yang akan dicek
 * returns {char} - grade berdasarkan nilai
 */
char getGrade(float score)
{
    if (score <= 55)
        return 'E';
    else if (score <= 65)
        return 'D';
    else if (score <= 75)
        return 'C';
    else if (score <= 85)
        return 'B';
    else
        return 'A';
}

/**
 * {*struct StudentData} student - Pointer ke data mahasiswa
 */
void checkIsExceedTheMinimumGrade(struct StudentData *student)
{
    bool isPass = true;
    if ((*student).gradeTugas == 'D' || (*student).gradeTugas == 'E')
    {
        isPass = false;
    }
    else if ((*student).gradeQuis == 'D' || (*student).gradeQuis == 'E')
    {
        isPass = false;
    }
    if ((*student).gradeAbsensi == 'D' || (*student).gradeAbsensi == 'E')
    {
        isPass = false;
    }
    if ((*student).gradePraktek == 'D' || (*student).gradePraktek == 'E')
    {
        isPass = false;
    }
    if ((*student).gradeUAS == 'D' || (*student).gradeUAS == 'E')
    {
        isPass = false;
    }

    // Set nilai apakah mahasiswa tersebut lulus atau tidak
    (*student).isPass = isPass;
}
/**
 * {struct StudentData[]} listStudent - daftar mahasiswa
 * {int} count - jumlah mahasiswa
 */
void printOutSummary(struct StudentData listStudent[], int count)
{
    int totalScoreAllStudent = 0;
    int totalPass = 0, totalFailed = 0;
    float averageAllStudent;

    for (int i = 0; i < count; i++)
    {
        struct StudentData currentStudent = listStudent[i];
        totalScoreAllStudent += currentStudent.nilaiRataRata;
        if (currentStudent.isPass == 1)
        {
            totalPass += 1;
        }
        else
        {
            totalFailed += 1;
        }
    }
    // Hitung rata-rata nilai mahasiswa
    averageAllStudent = (float)totalScoreAllStudent / count;
    printf("\n\n------------------------------\n");
    printf("Nilai rata-rata seluruh mahasiswa adalah: %.2f\n", averageAllStudent);
    printf("Jumlah mahasiswa yang lulus ada %d orang.\n", totalPass);
    printf("Jumlah mahasiswa yang gagal ada %d orang.\n", totalFailed);
    printf("\n------------------------------\n\n");
    printf("\nTekan enter untuk melanjutkan...");
    while (getchar() != '\n')
    {
    }
}

/**
 * Fungsi untuk menampilkan daftar referensi yang digunakan untuk mengerjakan tugas ini
 */
void menuReferenceList()
{
    printf("a. C Structures (https://www.w3schools.com/c/c_structs.php)\n");
    printf("b. C Library Function (atoi) (https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm)\n");

    printf("\nTekan enter untuk lanjut..\n");
    while (getchar() != '\n')
    {
    }
}