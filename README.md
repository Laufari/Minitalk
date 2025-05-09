#Minitalk 

- Comunicación entre Cliente y Servidor mediante Señales UNIX
Descripción: Minitalk es un proyecto en C que permite la comunicación entre un cliente y un servidor usando señales UNIX (SIGUSR1 y SIGUSR2). El servidor muestra su PID y recibe mensajes del cliente, imprimiéndolos rápidamente. La comunicación debe ser eficiente, sin que el servidor tarde más de 1 segundo en procesar 100 caracteres.

📂 Estructura

minitalk/
├── client.c            # Cliente
├── server.c            # Servidor
├── Makefile            # Compilación
└── README.md           # Documentación
🛠️ Instalación
Compilar:

make
Ejecutar el servidor:

./server
Ejecutar el cliente:

./client <PID> <message>
Limpiar archivos:

make clean
make fclean
🎯 Reglas
La comunicación entre cliente y servidor se realiza mediante SIGUSR1 y SIGUSR2.
El servidor debe procesar rápidamente los mensajes.
No debe haber errores ni fugas de memoria.
El cliente y servidor deben manejar señales con funciones como kill, signal, y otras permitidas por la norma.
🎁 Bonus
El servidor confirma cada señal recibida.
Soporte para caracteres Unicode.

🚀 Evaluación y Normas
El proyecto debe seguir las normas de la escuela 42.
La comunicación debe ser eficiente y rápida, asegurando que el servidor pueda procesar mensajes rápidamente.
El Makefile debe contener las reglas necesarias para compilar el proyecto correctamente.
