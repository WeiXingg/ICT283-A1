#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>

using namespace std;

/**
 * @class Vector
 * @brief  Templated data structure that stores any type of data
 *
 * This class is a vector that will handle the following functions:
 * Number of elements in it
 * Total size of vector
 * Retrieving and removing of elements at specified index
 * Adding of elements into vector
 * Copy constructor, Copy method and Overloaded assignment
 *
 * @author Wei Xing
 * @version 01
 * @date 15/06/2022 Wei Xing, Started
 *
 * @todo None for now
 *
 * @bug To the best of my knowledge, my program has no bugs
 */

/// Constant variable for initial vector size
const int INITIAL_ALLOCATION = 4;

template <class T>
class Vector
{
public:
    Vector();
    ~Vector();

    /**
     * Get size of vector
     * @param None
     * @return m_size
     */
    unsigned GetSize() const;

    /**
     * Add element to vector
     * @param any datatype
     * @return true/false
     */
    bool Add(T item);

    /**
     * Remove element at index
     * @param index
     * @return true/false
     */
    bool Remove(int index);

    /**
     * Retrieve element at index
     * @param index
     * @return return m_vector at index
     */
    T& At(int index);

    /**
     * Copy constructor
     * @param vector containing any datatype
     * @return new vector
     */
    Vector(const Vector<T>& initialiser);

    /**
     * Copy method
     * @param old and new vector containing any datatype
     * @return true/false
     */
    bool Copy(const Vector<T>& rhs, Vector<T>& newVector);

    /**
     * Overloaded assignment
     * @param vector containing any datatype
     * @return new vector
     */
    Vector<T>& operator = (const Vector<T>& rhs);

    unsigned GetAllocation() const; // commented out as used for testing only


private:
    /**
     * Get total size of vector
     * @param None
     * @return m_size
     */
    //unsigned GetAllocation() const;

    /// Total size of vector
    unsigned m_allocation;

    /// Number of items in the vector itself
    unsigned m_size;

    /// Pointer to vector
    T* m_vector;

};

template <class T>
Vector<T>::Vector() // Constructor
{
    m_allocation = 0;
    m_size = 0;
    m_vector = new T[INITIAL_ALLOCATION]; // Creation on heap
    if (m_vector != nullptr)
    {
        m_allocation = INITIAL_ALLOCATION;
    }
}

template <class T>
Vector<T>::~Vector() // Deconstructor
{
    if (m_vector != nullptr)
    {
        delete[] m_vector; // Deletion of vector
    }
    m_vector = nullptr; // Point to NULL
}

template <class T>
unsigned Vector<T>::GetSize() const // Return number of elements in vector
{
    return m_size;
}

template <class T>
unsigned Vector<T>::GetAllocation() const // return total size of vector
{
    return m_allocation;
}

template <class T>
bool Vector<T>::Add(T item) // Adding one element into vector
{
    if (m_size >= m_allocation) // Checking
    {
        return false;
    }
    else
    {
        if (m_size > (m_allocation / 2))
        {
            m_allocation *= 2; // Increase total size of vector by 2 times
            T* newVector = new T[m_allocation]; // New vector with the doubled size
            if (newVector != nullptr)
            {
                for(unsigned i = 0; i < m_size; i++)
                {
                    newVector[i] = m_vector[i];
                }
                delete[] m_vector;
                m_vector = newVector;
                newVector = nullptr;
            }
        }
        m_vector[m_size] = item;
        m_size++;
        return true;
    }
}

template <class T>
bool Vector<T>::Remove(int index) // Removing one element from vector based on index
{
    if (m_size >= m_allocation)
    {
        return false;
    }
    else
    {
        for (unsigned i = index; i < m_size - 1; i++)
        {
            m_vector[i] = m_vector[i+1];
        }
        m_size--;
        return true;
    }
}

template <class T>
T& Vector<T>::At(int index) // Retrieving one element from vector based on index
{
    return m_vector[index];
}

template <class T>
Vector<T>::Vector(const Vector<T>& initialiser)
{
    m_vector = nullptr;
    Copy(initialiser, *this);
}

template <class T>
bool Vector<T>::Copy(const Vector<T>& rhs, Vector<T>& newVector)
{
    if (rhs.m_vector != nullptr)
    {
        if(newVector.m_vector != nullptr) // To check if new vector is pointing to NULL
        {
            delete[] newVector.m_vector;
            newVector.m_vector = nullptr;
        }
        newVector.m_allocation = rhs.m_allocation; // Set new vector total size using old vector total size
        newVector.m_size = rhs.m_size; // Set new vector number of elements using old vector number
        newVector.m_vector = new T[rhs.m_allocation]; // Creation on heap using old vector total size
        for(unsigned i = 0; i < rhs.m_size; i++)
        {
            newVector.m_vector[i] = rhs.m_vector[i];
        }
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& rhs)
{
    Copy(rhs, *this);
    return *this;
}

#endif
