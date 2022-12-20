#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "ESP32-C3-FY"                                                         //change this
 
const char AWS_IOT_ENDPOINT[] = "a1q5hkjxqupius-ats.iot.sa-east-1.amazonaws.com";       //change this
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAKt1xYF57mtpaA/oqMwPL7azCSQIMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjEyMTgxNDQ3
MzZaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDlVbLluy8KyXfqSHTK
Zl37sLlBCfFpyPNn+BgtMNYp01JB2YQqzeBDY3xCfE5vu+6yL6M87bKHU1LD5YR7
qGWa3qa7CvSSSgi74f+aI9k7yMU0THpuEYOOK0tZMxK6VeBBb8cQZFRe+hh11SEX
TzVxI2VSUnh7nxeCrfqLuEAU5RZ8HTG+S8GGLDZz1SvC2g0KCjjenMHg8BGKTV1R
2dv1MZIn1a7Fq5tijzEpAWxFA4eGk6ujAxyjmizg4aRFNdVC+CrpXhqs2ifnbtmQ
+NbMdc5FwGCFlVPXKfNzbh68mdRjDEWCeU5ngO8WAKOWTlbrgvWy1fANr+qUXHEE
vjm3AgMBAAGjYDBeMB8GA1UdIwQYMBaAFO48EM7VhObvVD90i5oTeWB8MjU0MB0G
A1UdDgQWBBTjH+mL9Oo2cAp0YidpVPaRvxuzYjAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAzJxEMeQhZ5NeCnMh9rMcJmN6
3ljsTqmCbgNWEo5s1B634bCHqSf1a6jWaFRMoZvVs0wOD6Dd+UXiHD7yhRpaKWCW
LRJnGmTUm3rombpu8uA84je9IIVyddyisly/7EaZVhsiIL19LNk/C4rfQoEyXp79
27bYsJgWHVUi6UOGVgjRtvhzYm5ql+x0YfQjCIke6X8FUHnBm0+wntswLWXvm/6W
qMXSi7brobysS9BLOohzv7reqfpBep/ucU+moF8KRcRXlEOtjk/yqwa1iKa1aK9u
gTinxqjJ8wfV7u5yoySB/QWVKXYfH+lRvTIPwCcYNBMcR/rGyhAzhcUdPVPGYw==
-----END CERTIFICATE-----
)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEA5VWy5bsvCsl36kh0ymZd+7C5QQnxacjzZ/gYLTDWKdNSQdmE
Ks3gQ2N8QnxOb7vusi+jPO2yh1NSw+WEe6hlmt6muwr0kkoIu+H/miPZO8jFNEx6
bhGDjitLWTMSulXgQW/HEGRUXvoYddUhF081cSNlUlJ4e58Xgq36i7hAFOUWfB0x
vkvBhiw2c9UrwtoNCgo43pzB4PARik1dUdnb9TGSJ9WuxaubYo8xKQFsRQOHhpOr
owMco5os4OGkRTXVQvgq6V4arNon527ZkPjWzHXORcBghZVT1ynzc24evJnUYwxF
gnlOZ4DvFgCjlk5W64L1stXwDa/qlFxxBL45twIDAQABAoIBAQDVbUb7U5N5B3wI
1fuS7Wejt5kAdT9tgm08IgBl9iApdpgD3mmI6GZAcNKQkVzx0UVYIMtbBZ9zH1FU
LEJ6ToKYeYNTaOOpTSsJp06X5ariX3tfq5j43GXBJnuN/OD99rOoUl1A3Q5EAZ5H
8txD9Bw5OYau8T9dVPatUDpuUz+X8MRYa8XUcEDi9jyH23hEOGLcge54gpDmpiQZ
9ly3ZX1FwEdhXIpZRyPyXzha9ndjpnnxxuDk3HYBU4FuzDmvg4VHHpUOo7OymQ+J
w671LuFxhKM5PsG6xGvl2ccaPAP1vqRnIfhsB5Jw1sCVT9SECnqvsKWHtg6rzh+w
6I+r2PoZAoGBAPLUOMRjJSGzPdA0uT/pcpASmkebcvwBWIDD64luwKq4v3NUEIS7
rzE7AUp/Wa51sV4SGpc4mH0HOSiN4Tc1GtJNWi3A/qQlsrdXe3tK1XkuYVi9Izr+
CP0dNO911fQhOwoMWcDnyfPn3eNvx6UDeEpCybGhHFbpGEBLO5ps9o4lAoGBAPHG
GrB4fFl0YrjxL3jTnQZfAwAj2/gk4JvTeudo8lBSE5mWnpRLonGYIFOOyNx2aMQt
IJfBeetNaYnbbeQBCUQdw+pSxF2baVQ36RcTNmXjh13ZOmIevoG9VlokFnSID1rn
h3njcABGZ8TV8MJIlLxb6kgRW3vc5PLf1BqvQ/urAoGAcsx/1eBlYoxBkdgLKDru
TUxuIaJM9vSP6bg19zAj59IVuKkqcgXk6ipSDu0r8b10T9vRNGKuPJWYoSKKMbZq
arflBTJzcBjeZ6z1FLGpQHP7057/M9l7WGZhaz/TGWpIZhS2resm36djkC19Pfbo
/HqcrdxT8IacT3EByZzv5v0CgYEAxL2iZkwFVH3jAAAz0yzQMKkMNgb4LxtDM0qK
TtkVpcrEbE0myiIqFCno1FXymYQ5iLn4NcWZQqMB6M6Iw+sb8TQPgxTK+ilHMuM0
aDSYJZ1bQEFOwx2lhMngBQYsx7MYW67gjY1ITND+DCzT+CU783MQWIjXWxnLrN/7
J6PLvHUCgYEA3+7eKddGigvtE9Ix0KuqI752SYjyCL4dkuXxQnpediJGMLnatjO9
fj5jU2gV6W5+wLLY6tJTPPz8Y52MqkF203mU0lnBTjOylrlX/13yZp1gulCa3cyz
I/1l2XzDjSNrCFSby3oseRqMi1/YhE9A4pZixQqL/2vRIU8JDidIooM=
-----END RSA PRIVATE KEY-----
)KEY";