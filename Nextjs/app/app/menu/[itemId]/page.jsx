"use client"

import axios from 'axios'
import { useParams } from 'next/navigation'
import React, { useEffect, useState } from 'react'

const page = () => {
    const {itemId} = useParams()

    const [orders, setOrders] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    const fetchOrders = async () => {
      try {
        const response = await axios.get(`http://localhost:3000/api/orders/${itemId}`);
        setOrders(response.data.data?.foods || []);
      } catch (err) {
        console.error('Error fetching orders:', err);
        setError('Failed to load menu items');
      } finally {
        setLoading(false);
      }
    };

    fetchOrders();
  }, []);

    console.log(itemId)
  return (
    <div>{itemId}</div>
  )
}

export default page