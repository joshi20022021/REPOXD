#include <iostream>
#include <limits>
#include "GestorPasajeros.h" // Incluir GestorPasajeros en lugar de GestorAviones

int main() {
    int opcion, subOpcion;
    GestorPasajeros gestorPasajeros; // Usar GestorPasajeros en lugar de GestorAviones

    do {
        // Menú principal
        std::cout << "|---------------MENU----------------|" << std::endl;
        std::cout << "|       1. Carga de aviones         |" << std::endl;
        std::cout << "|      2. Carga de pasajeros        |" << std::endl;
        std::cout << "|     3. Procesar registro          |" << std::endl;
        std::cout << "|      4. Consultar pasajero        |" << std::endl;
        std::cout << "|      5. Visualizar reportes       |" << std::endl;
        std::cout << "|             6. Salir              |" << std::endl;
        std::cout << "|-----------------------------------|" << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        // Limpiar el búfer de entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Lógica para ejecutar la opción seleccionada
        switch (opcion) {
            case 1: {
                // Lógica para cargar aviones
                break;
            }
            case 2: {
                // Obtener la ruta del archivo de entrada
                std::string rutaArchivo;
                std::cout << "Ingrese la ruta del archivo JSON de pasajeros: ";
                std::getline(std::cin, rutaArchivo);

                // Llamar a la función cargarPasajerosDesdeArchivo con la ruta del archivo
                gestorPasajeros.cargarPasajerosDesdeArchivo(rutaArchivo);
                gestorPasajeros.mostrarColaPasajeros(); // Mostrar la cola de pasajeros
                break;
            }
            case 3: {
                // Lógica para procesar registro
                break;
            }
            case 4: {
                // Lógica para consultar pasajero
                break;
            }
            case 5: {
                do {
                    // Submenú de reportes
                    std::cout << "---------------REPORTES---------------" << std::endl;
                    std::cout << "|  1. Lista de aviones disponibles   |" << std::endl;
                    std::cout << "|2. Lista de aviones en mantenimiento|" << std::endl;
                    std::cout << "|    3. Mostrar pila de equipaje     |" << std::endl;
                    std::cout << "|  4. Mostrar pasajeros ordenados    |" << std::endl;
                    std::cout << "|   5. Volver al menú principal      |" << std::endl;
                    std::cout << "Ingrese una opción: ";
                    std::cin >> subOpcion;

                    // Limpiar el búfer de entrada
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (subOpcion) {
                        case 1:
                            // Lógica para mostrar lista de aviones disponibles
                            break;
                        case 2:
                            // Lógica para mostrar lista de aviones en mantenimiento
                            break;
                        case 3:
                            // Lógica para mostrar pila de equipaje
                            break;
                        case 4:
                            // Lógica para mostrar pasajeros ordenados
                            break;
                        case 5:
                            // Volver al menú principal
                            break;
                        default:
                            std::cout << "Opción inválida. Por favor, seleccione una opción válida." << std::endl;
                            break;
                    }
                } while (subOpcion != 5);
                break;
            }
            case 6:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Por favor, seleccione una opción válida." << std::endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
