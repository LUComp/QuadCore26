## PATH FINDING

* **Input:** 
    - **Start Point:** $(a, b, c)$, where $a, b, c \in \mathbb{R}$. $(0, 0, 0)$ by default
    - **End Point:** $(x, y, z)$, e.g. $(-23, 11, -7)$
    - **Step Length**: Step Length ($SL$), meaning the distance the robot moves for a full motion.
* **Output:** A list of all coordinates that are exact multiples of the $SL$ from the origin towards the end point.

---

### Related Formulae

$$\Delta x = x_{end} - x_{start}$$
$$\Delta y = y_{end} - y_{start}$$
$$\Delta z = z_{end} - z_{start}$$

---

$$D = \sqrt{\Delta x^2 + \Delta y^2 + \Delta z^2}$$

---

$$x_i = x_{start} + \left( \frac{\Delta x}{D} \times SL \right) \times i$$
$$y_i = y_{start} + \left( \frac{\Delta y}{D} \times SL \right) \times i$$
$$z_i = z_{start} + \left( \frac{\Delta z}{D} \times SL \right) \times i$$

---

**Constraint:**

$$where \ i \in \mathbb{Z}^+, \quad 0 < i \le \lfloor \frac{D}{SL} \rfloor$$
