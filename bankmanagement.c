#include <stdio.h>
#include <string.h>

int main() {
    // Variable Declarations
    int accnum, assistance, foundfname, foundsname, option, key;
    char lang;
    char fname, sname;
    float withdraw, balance, deposit;
    int pwd1, pwd2, extpwd;
    char gender[100];
    int totalacc, maxacc = 100, x = 0;
    int pwd[100];
    char acc[100][3];
    float accdetails[100][4];  

    printf("*****Bank Initialization*****\n");
    printf("Can only be done by the manager\n");
    key = 1234;

    do {
        printf("Enter key: ");
        scanf("%d", &key);
        if (key != 1234) {
            printf("Enter correct key!\n");
        }
    } while (key != 1234);

    printf("Enter the number of accounts to be on the server (maximum %d): ", maxacc);
    scanf("%d", &totalacc);

    if (totalacc > maxacc) {
        printf("Maximum account limit exceeded. Please restart and enter a number less than or equal to %d\n", maxacc);
        return 1;
    }

    while (1) {  // Infinite loop
        printf("*****DEUTCH BANKING NETWORK*****\n\n");
        printf("Welcome to Commerce Banking Network-CBN\n\n");
        printf("G--German\n");
        printf("E--English\n\n");
        printf("Please select your language, enter the initials of the language given: ");
        scanf(" %c", &lang);

        while (lang != 'G' && lang != 'E') {
            printf("Enter from the options above!\n");
            printf("G--German\n");
            printf("E--English\n\n");
            printf("Please select your language, enter the initials of the language given: ");
            scanf(" %c", &lang);
        }

        switch (lang) {
            case 'E':
                printf("Language selected: English\n");
                do {
                    printf("1--New Account\n");
                    printf("2--Existing Account\n");
                    printf("Choose an option from above: ");
                    scanf("%d", &option);
                    if (option != 1 && option != 2) {
                        printf("Enter from the options above!\n");
                    }
                } while (option != 1 && option != 2);

                switch (option) {
                    case 1:
                        if (x >= totalacc) {
                            printf("Account limit reached. Call manager to increase the limit.\n");
                            printf("Enter manager key to increase limit: ");
                            scanf("%d", &key);
                            if (key == 1234) {
                                printf("Enter the new total number of accounts (must be <= %d): ", maxacc);
                                int new_total;
                                scanf("%d", &new_total);
                                if (new_total > totalacc && new_total <= maxacc) {
                                    totalacc = new_total;
                                    printf("Account limit increased successfully.\n");
                                } else {
                                    printf("Invalid new limit.\n");
                                }
                            } else {
                                printf("Incorrect key. Returning to main menu.\n");
                                break;
                            }
                        }

                        printf("Enter your first name initials: ");
                        scanf(" %c", &acc[x][1]);
                        printf("Enter your second name initials: ");
                        scanf(" %c", &acc[x][2]);

                        do {
                            printf("M-Male\nF-Female\nSelect your gender: ");
                            scanf(" %c", &gender[x]);
                            if (gender[x] != 'M' && gender[x] != 'F') {
                                printf("Choose from the above genders!\n");
                            }
                        } while (gender[x] != 'M' && gender[x] != 'F');

                        do {
                            printf("*Your NIC number will be your passcode*\n");
                            printf("Enter NIC number: ");
                            scanf("%d", &pwd1);
                            printf("Confirm NIC number: ");
                            scanf("%d", &pwd2);
                            if (pwd1 != pwd2) {
                                printf("Please enter correct NIC number again!\n");
                            }
                        } while (pwd1 != pwd2);

                        pwd[x] = pwd1;
                        accdetails[x][1] = 0;           // Initial balance
                        accdetails[x][2] = -100;        // Overdraft limit
                        accdetails[x][3] = 200;         // Withdrawal limit
                        x++;

                        printf("Your Account is successfully created!\n");
                        printf("Some info for new users:\n");
                        printf("*Your current balance is $0.00\n");
                        printf("*You have an overdraft limit of $100\n");
                        printf("*You have a withdrawal limit of $200\n\n");
                        printf("After a year your overdraft and withdrawal limit will be increased.\n\n");
                        printf("Thank you for joining with us.\n");
                        printf("Take Care.\n\n\n\n\n");
                        break;

                    case 2:
                        do {
                            printf("Enter your first name initial: ");
                            scanf(" %c", &fname);
                            printf("Enter your second name initial: ");
                            scanf(" %c", &sname);

                            foundfname = 0;
                            foundsname = 0;
                            for (int i = 0; i < x; i++) {
                                if (acc[i][1] == fname) {
                                    foundfname = 1;
                                    if (acc[i][2] == sname) {
                                        foundsname = 1;
                                        break;
                                    }
                                }
                            }

                            if (!foundfname || !foundsname) {
                                printf("Enter correct initials!\n");
                            }
                        } while (!foundfname || !foundsname);

                        do {
                            printf("Enter your NIC number: ");
                            scanf("%d", &extpwd);
                            foundfname = 0;
                            for (int i = 0; i < x; i++) {
                                if (pwd[i] == extpwd) {
                                    foundfname = 1;
                                    break;
                                }
                            }

                            if (!foundfname) {
                                printf("Please enter correct NIC number!\n");
                            }
                        } while (!foundfname);

                        do {
                            printf("1-Withdraw\n");
                            printf("2-Deposit\n");
                            printf("Select the assistance you want, enter the respective number: ");
                            scanf("%d", &assistance);

                            switch (assistance) {
                                case 1:
                                    printf("Enter the amount you want to withdraw: ");
                                    scanf("%f", &withdraw);
                                    balance = accdetails[x][1];

                                    if (balance - withdraw >= -100 && withdraw <= 200) {
                                        accdetails[x][1] -= withdraw;
                                        printf("Transaction successful! Your current balance is $%.2f\n", accdetails[x][1]);
                                    } else {
                                        printf("Insufficient funds or withdrawal limit exceeded.\n");
                                    }
                                    break;

                                case 2:
                                    printf("Enter the amount you want to deposit: ");
                                    scanf("%f", &deposit);
                                    accdetails[x][1] += deposit;
                                    printf("Transaction successful! Your current balance is $%.2f\n", accdetails[x][1]);
                                    break;

                                default:
                                    printf("Enter from the options above!\n");
                            }
                        } while (assistance != 1 && assistance != 2);

                        break;

                    default:
                        printf("Enter from the options above!\n");
                }

                break;

            case 'G':
                printf("Language selected: Deutsch\n");
                do {
                    printf("1--Neues Konto\n");
                    printf("2--Bestehendes Konto\n");
                    printf("Wählen Sie eine Option aus den oben genannten: ");
                    scanf("%d", &option);
                    if (option != 1 && option != 2) {
                        printf("Wählen Sie aus den oben genannten Optionen!\n");
                    }
                } while (option != 1 && option != 2);

                switch (option) {
                    case 1:
                        if (x >= totalacc) {
                            printf("Kontolimit erreicht. Rufen Sie den Manager an, um das Limit zu erhöhen.\n");
                            printf("Geben Sie den Manager-Schlüssel ein, um das Limit zu erhöhen: ");
                            scanf("%d", &key);
                            if (key == 1234) {
                                printf("Geben Sie die neue Gesamtzahl der Konten ein (muss <= %d sein): ", maxacc);
                                int new_total;
                                scanf("%d", &new_total);
                                if (new_total > totalacc && new_total <= maxacc) {
                                    totalacc = new_total;
                                    printf("Kontolimit erfolgreich erhöht.\n");
                                } else {
                                    printf("Ungültiges neues Limit.\n");
                                }
                            } else {
                                printf("Falscher Schlüssel. Zurück zum Hauptmenü.\n");
                                break;
                            }
                        }

                        printf("Geben Sie die Initialen Ihres Vornamens ein: ");
                        scanf(" %c", &acc[x][1]);
                        printf("Geben Sie die Initialen Ihres Nachnamens ein: ");
                        scanf(" %c", &acc[x][2]);

                        do {
                            printf("M-Männlich\nF-Weiblich\nWählen Sie Ihr Geschlecht: ");
                            scanf(" %c", &gender[x]);
                            if (gender[x] != 'M' && gender[x] != 'F') {
                                printf("Wählen Sie aus den oben genannten Geschlechtern!\n");
                            }
                        } while (gender[x] != 'M' && gender[x] != 'F');

                        do {
                            printf("*Ihre NIC-Nummer wird Ihr Passwort sein*\n");
                            printf("Geben Sie die NIC-Nummer ein: ");
                            scanf("%d", &pwd1);
                            printf("Bestätigen Sie die NIC-Nummer: ");
                            scanf("%d", &pwd2);
                            if (pwd1 != pwd2) {
                                printf("Bitte geben Sie die richtige NIC-Nummer erneut ein!\n");
                            }
                        } while (pwd1 != pwd2);

                        pwd[x] = pwd1;
                        accdetails[x][1] = 0;           // Anfangsguthaben
                        accdetails[x][2] = -100;        // Überziehungslimit
                        accdetails[x][3] = 200;         // Auszahlungslimit
                        x++;

                        printf("Ihr Konto wurde erfolgreich erstellt!\n");
                        printf("Einige Informationen für neue Benutzer:\n");
                        printf("*Ihr aktuelles Guthaben beträgt $0.00\n");
                        printf("*Sie haben ein Überziehungslimit von $100\n");
                        printf("*Sie haben ein Auszahlungslimit von $200\n\n");
                        printf("Nach einem Jahr wird Ihr Überziehungs- und Auszahlungslimit erhöht.\n\n");
                        printf("Vielen Dank, dass Sie sich uns angeschlossen haben.\n");
                        printf("Passen Sie auf sich auf.\n\n\n\n\n");
                        break;

                    case 2:
                        do {
                            printf("Geben Sie die Initialen Ihres Vornamens ein: ");
                            scanf(" %c", &fname);
                            printf("Geben Sie die Initialen Ihres Nachnamens ein: ");
                            scanf(" %c", &sname);

                            foundfname = 0;
                            foundsname = 0;
                            for (int i = 0; i < x; i++) {
                                if (acc[i][1] == fname) {
                                    foundfname = 1;
                                    if (acc[i][2] == sname) {
                                        foundsname = 1;
                                        break;
                                    }
                                }
                            }

                            if (!foundfname || !foundsname) {
                                printf("Geben Sie die richtigen Initialen ein!\n");
                            }
                        } while (!foundfname || !foundsname);

                        do {
                            printf("Geben Sie Ihre NIC-Nummer ein: ");
                            scanf("%d", &extpwd);
                            foundfname = 0;
                            for (int i = 0; i < x; i++) {
                                if (pwd[i] == extpwd) {
                                    foundfname = 1;
                                    break;
                                }
                            }

                            if (!foundfname) {
                                printf("Bitte geben Sie die richtige NIC-Nummer ein!\n");
                            }
                        } while (!foundfname);

                        do {
                            printf("1-Abheben\n");
                            printf("2-Einzahlen\n");
                            printf("Wählen Sie die gewünschte Hilfe aus, geben Sie die entsprechende Nummer ein: ");
                            scanf("%d", &assistance);

                            switch (assistance) {
                                case 1:
                                    printf("Geben Sie den Betrag ein, den Sie abheben möchten: ");
                                    scanf("%f", &withdraw);
                                    balance = accdetails[x][1];

                                    if (balance - withdraw >= -100 && withdraw <= 200) {
                                        accdetails[x][1] -= withdraw;
                                        printf("Transaktion erfolgreich! Ihr aktuelles Guthaben beträgt $%.2f\n", accdetails[x][1]);
                                    } else {
                                        printf("Unzureichende Mittel oder Auszahlungslimit überschritten.\n");
                                    }
                                    break;

                                case 2:
                                    printf("Geben Sie den Betrag ein, den Sie einzahlen möchten: ");
                                    scanf("%f", &deposit);
                                    accdetails[x][1] += deposit;
                                    printf("Transaktion erfolgreich! Ihr aktuelles Guthaben beträgt $%.2f\n", accdetails[x][1]);
                                    break;

                                default:
                                    printf("Wählen Sie aus den oben genannten Optionen!\n");
                            }
                        } while (assistance != 1 && assistance != 2);

                        break;

                    default:
                        printf("Wählen Sie aus den oben genannten Optionen!\n");
                }

                break;

            default:
                printf("Wählen Sie aus den oben genannten Optionen!\n");
        }
    }

    return 0;
}
