// Bubble sort algorithm 

// Input elements: array of iterable  elements

public func bubbleSort<T> (_ elements: [T]) -> [T] where T: Comparable {
  return bubbleSort(elements, <)
}

public func bubbleSort<T> (_ elements: [T], _ comparison: (T,T) -> Bool) -> [T]  {
  var arr = elements
  
  for i in 0..<arr.count {
    for k in 1..<arr.count-i {
      if comparison(arr[k], arr[k-1]) {
        let temp = arr[k-1]
        arr[k-1] = arr[k]
        arr[k] = temp
      }
    }
  }
  
  return arr
}
