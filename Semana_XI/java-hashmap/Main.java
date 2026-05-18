import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) {

        HashMap<Integer, Estudiante> estudiantes = new HashMap<>();

        String archivoCSV = "estudiantes.csv"; // cambia la ruta si hace falta


        try (BufferedReader br = new BufferedReader(new FileReader(archivoCSV))) {

            String linea;

            while ((linea = br.readLine()) != null) {

                String[] datos = linea.split(",");

                int id = Integer.parseInt(datos[0]);
                String nombre = datos[1];

                if (!estudiantes.containsKey(id)) {

                    estudiantes.put(id, new Estudiante(id, nombre));

                } else {
                    System.out.println("Duplicado ignorado: " + id);
                }
            }

        } catch (Exception e) {
            System.out.println("Error leyendo CSV: " + e.getMessage());
        }


        int buscarId = 1001;

        if (estudiantes.containsKey(buscarId)) {
            System.out.println("\n=== ESTUDIANTE ENCONTRADO ===");
            System.out.println(estudiantes.get(buscarId));
        } else {
            System.out.println("No existe estudiante.");
        }


        int eliminarId = 1002;

        if (estudiantes.containsKey(eliminarId)) {
            estudiantes.remove(eliminarId);
            System.out.println("\nEstudiante eliminado.");
        } else {
            System.out.println("No existe estudiante para eliminar.");
        }


        System.out.println("\n=== HASHMAP COMPLETO ===");

        for (Integer key : estudiantes.keySet()) {
            System.out.println("-------------------");
            System.out.println(estudiantes.get(key));
        }


        System.out.println("\nTotal estudiantes: " + estudiantes.size());
    }
}