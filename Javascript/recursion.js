function replicate(times, number) {
    // Ejemplo sencillo resolucion mediante rescursion
    return times <= 0 ? [] : [number].concat(replicate(times - 1, number));
}