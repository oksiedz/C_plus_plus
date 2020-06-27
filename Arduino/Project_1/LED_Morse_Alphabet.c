const int pin = 13;
const int d_break = 1000; //digit break
const int l_break = 3000; //letter break
const int w_break = 5000; //word break
const int dot_l = 1000; //lenght of dot
const int dash_l = 3000; //lenght of dot

void setup()
{
  pinMode(pin, OUTPUT);
}

void digit_break()
{
  delay(d_break);
}

void letter_break()
{
  delay(l_break);
}

void word_break()
{
  delay(w_break);
}

void led_off()
{
  digitalWrite(pin, LOW);
}

void dot()
{
  digitalWrite(pin, HIGH);
  delay(dot_l);
  led_off();
}

void dash()
{
  digitalWrite(pin, HIGH);
  delay(dash_l);
  led_off();
}

void letter_t()
{
  dash();
}

void letter_o()
{
  dash();
  digit_break();
  dash();
  digit_break();
  dash();
}

void letter_m()
{
  dash();
  digit_break();
  dash();
}

void letter_a()
{
  dot();
  digit_break();
  dash();
}

void letter_s()
{
  dot();
  digit_break();
  dot();
  digit_break();
  dot();
}

void letter_z()
{
  dash();
  digit_break();
  dash();
  digit_break();
  dot();
  digit_break();
  dot();
}

void letter_j()
{
  dot();
  digit_break();
  dash();
  digit_break();
  dash();
  digit_break();
  dash();
}

void letter_n()
{
  dash();
  digit_break();
  dot();
}

void letter_k()
{
  dash();
  digit_break();
  dot();
  digit_break();
  dash();
}

void letter_i()
{
  dot();
  digit_break();
  dot();
}

void letter_e()
{
  dot();
}

void letter_d()
{
  dash();
  digit_break();
  dot();
  digit_break();
  dot();
}


void loop()
{

  //Led will be enabled and disabled in a way that it will show: tomasz jan oksiedzki in morse alphabet
  //-/---/--/.-/.../--..//.---/.-/-.//---/-.-/.../.././-../--../-.-/.//
  word_break();
  letter_t();
  letter_break();
  letter_o();
  letter_break();
  letter_m();
  letter_break();
  letter_a();
  letter_break();
  letter_s();
  letter_break();
  letter_z();
  word_break();
  letter_j();
  letter_break();
  letter_a();
  letter_break();
  letter_n();
  word_break();
  letter_o();
  letter_break();
  letter_k();
  letter_break();
  letter_s();
  letter_break();
  letter_i();
  letter_break();
  letter_e();
  letter_break();
  letter_d();
  letter_break();
  letter_z();
  letter_break();
  letter_k();
  letter_break();
  letter_i();
  word_break();
}