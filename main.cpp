// inisialisasi trigger dan echo dari sensor ultrasonic dengan trigger menggunakan D0 dan echo menggunakan D1
int trigPin = D0;
int echoPin = D1;

// inisialisasi variabel untuk perhitungan jarak
long time;
int dist;

// inisialisasi obyek servo dari library
Servo servo;

void setup()
{
    // setup trigger, echo, dan servo agar dikenali oleh NodeMcu
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    servo.attach(D2);
}

void loop()
{
    // trigger mengirimkan gelombang ultrasonic saat diberi tegangan HIGH
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // menghitung waktu kedatangan gelombang oleh echo saat diberi tegangan HIGH
    time = pulseIn(echoPin, HIGH);

    // menghitung jarak dengan waktu dibagi 2 berdasarkan waktu sampai dan kembali
    dist = 0.034 * time / 2;

    // jika obyek ada pada jarak tertentu servo akan terbuka
    if (dist <= 10)
    {
        servo.write(180);
    }
    else
    // jika tidak servo tertutup
    {
        servo.write(0);
    }

    // memberikan delay untuk proses yang dilakukan
    delay(1000);
}