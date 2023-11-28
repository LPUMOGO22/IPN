	list p=16f84 ;microcontrolador a usar
	radix hex  ;trabajar en hexadecimal

status equ 0x03    ;direciones de puertos y registros a utilzar
porta equ 0x05
portb equ 0x06
pcl equ 0x02

	org 0x00     ;a partir de donde de integrara el programa

inicio
		bsf status,5   ; ingresar al registro status para asignat las direcciones
		movlw b'00011111' ; cinco entradas, número en binario
		movwf porta         ; en el regristo A
		movlw 0x00       ; solo ceros en el registro salida puerto B
		movwf portb
		bcf status,5      ; salimos del registro de status

principal				; programa Principal
		movf porta,0		; mover lo que entra 
		andlw b'00011111'    ; operacion and con el valor
		call display	; llamar a la subrutina Dispaly
		movwf portb	; mover a la salida
		goto principal	; cerrar la subrutina

display
		addwf pcl,1    ; realizar el incrementoen uno y gurdarlo en el registro
		retlw 0x3F		; decodificación de cada numero del 0 a la F
		retlw 0x06
		retlw 0x6B
		retlw 0x4F
		retlw 0x66
		retlw 0x6D
		retlw 0x7D
		retlw 0x07
		retlw 0x7F
		retlw 0x67
		retlw 0x77
		retlw 0x7C
		retlw 0x39
		retlw 0x5E
		retlw 0x79
		retlw 0x71

	END				; fin del programa
